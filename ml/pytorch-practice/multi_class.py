
import numpy as np
import pandas as pd
import torch
import torch.nn as nn
import seaborn as sns


cars_file = 'https://gist.githubusercontent.com/noamross/e5d3e859aa0c794be10b/raw/b999fb4425b54c63cab088c0ce2c0d6ce961a563/cars.csv'
cars = pd.read_csv(cars_file)
cars.head()

#%% convert data into tensor
sns.scatterplot(x='wt', y='mpg', data=cars)
sns.regplot(x='wt', y='mpg', data=cars)

X_list = cars.wt.values
# (32, ) -> (32, 1)
X_np = np.array(X_list, dtype=np.float32).reshape(-1,1)
X_np.shape

y_list = cars.mpg.values.tolist() # (32,)

# tensor from np array
X = torch.from_numpy(X_np)
# tensor from python list
y = torch.tensor(y_list)

#%% training
# how to initialize W and b with such as xaiver init?
w = torch.rand(1, requires_grad=True, dtype=torch.float32) # (1,)
b = torch.rand(1, requires_grad=True, dtype=torch.float32)

num_epochs = 1000
learning_rate = 0.001

for epoch in range(num_epochs):
    for i in range(len(X)):
        y_pred = X[i] * w + b
        loss_tensor = torch.pow(y_pred - y[i], 2) # (1,)

        #backward
        loss_tensor.backward()
        # extract losses
        # 주의
import numpy as np
import pandas as pd
import torch
import torch.nn as nn
import seaborn as sns


cars_file = 'https://gist.githubusercontent.com/noamross/e5d3e859aa0c794be10b/raw/b999fb4425b54c63cab088c0ce2c0d6ce961a563/cars.csv'
cars = pd.read_csv(cars_file)
cars.head()

#%% convert data into tensor
sns.scatterplot(x='wt', y='mpg', data=cars)
sns.regplot(x='wt', y='mpg', data=cars)

X_list = cars.wt.values
# (32, ) -> (32, 1)
X_np = np.array(X_list, dtype=np.float32).reshape(-1,1)
X_np.shape

y_list = cars.mpg.values.tolist() # (32,)

# tensor from np array
X = torch.from_numpy(X_np)
# tensor from python list
y = torch.tensor(y_list)

#%% training
# how to initialize W and b with such as xaiver init?
w = torch.rand(1, requires_grad=True, dtype=torch.float32) # (1,)
b = torch.rand(1, requires_grad=True, dtype=torch.float32)

num_epochs = 10
learning_rate = 0.001

loss_values = []

for epoch in range(num_epochs):
    epoch_losses = []  # 에폭마다의 손실을 저장할 리스트
    for i in range(len(X)):
        y_pred = X[i] * w + b
        loss_tensor = torch.pow(y_pred - y[i], 2) # (1,)

        #backward
        loss_tensor.backward()
        # extract losses
        # 주의
        # 1-요소 텐서를 Python 스칼라로 변환하려면 .item()을 사용하는 것이 더 좋습니다.
        # .data를 사용하면 PyTorch의 계산 그래프를 우회할 수 있으므로, 잘못된 기울기 계산을 초래할 수 있습니다.
        loss_value = loss_tensor.data[0] # (1,) but need index.
        epoch_losses.append(loss_tensor.item())  # .item()을 사용하여 텐서에서 스칼라 값 추출

        # update weights and biases
        # deactivate O2 gradient, we have manual gradient
        with torch.no_grad():
            w -= w.grad * learning_rate
            b -= b.grad * learning_rate
            # requires_grad=False 이면, 기울기가 계산 되지 않음. None 반환.
            # PyTorch에서 기울기는 누적되는 특성이 있습니다.
            # 즉, .backward()가 호출될 때마다 기울기가 텐서의 .grad 속성에 추가됩니다.
            # 따라서, 각 학습 단계의 시작 부분에서(또는 매개변수를 업데이트한 후에)
            # 모든 최적화된 매개변수의 기울기를 0으로 설정하여 이전 반복에서의 누적을 방지하는 것이 중요합니다
            w.grad.zero_()
            b.grad.zero_()

    # 에폭의 평균 손실을 계산하고 저장
    epoch_loss = np.mean(epoch_losses)
    loss_values.append(epoch_loss)

import matplotlib.pyplot as plt

# 훈련이 끝난 후 손실 값의 감소를 시각화
plt.plot(loss_values, '-o', label='Training Loss')
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.title('Loss Value Over Epochs')
plt.legend()
plt.show()
#%%

#%%
