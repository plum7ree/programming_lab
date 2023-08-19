import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np

# Define the Autoencoder class
class Autoencoder(nn.Module):
    def __init__(self, input_size, hidden_size):
        super(Autoencoder, self).__init__()
        self.encoder = nn.Sequential(
            nn.Linear(input_size, hidden_size),
            nn.ReLU()
        )
        self.decoder = nn.Sequential(
            nn.Linear(hidden_size, input_size),
            nn.Sigmoid()
        )
        
    def forward(self, x):
        encoded = self.encoder(x)
        decoded = self.decoder(encoded)
        return decoded

# Hyperparameters
input_size = 8
hidden_size = 3
learning_rate = 0.1
epochs = 1000

# Create the model and optimizer
autoencoder = Autoencoder(input_size, hidden_size)
criterion = nn.MSELoss()
optimizer = optim.SGD(autoencoder.parameters(), lr=learning_rate)

# Generate example input data
input_data = torch.rand(10, input_size)

# Training loop
for epoch in range(epochs):
    optimizer.zero_grad()
    output = autoencoder(input_data)
    loss = criterion(output, input_data)
    loss.backward()
    optimizer.step()
    if (epoch + 1) % 100 == 0:
        print(f"Epoch [{epoch+1}/{epochs}], Loss: {loss.item():.4f}")

# Encode and decode the data
encoded_data = autoencoder.encoder(input_data)
decoded_data = autoencoder.decoder(encoded_data)

print("Original Data:\n", input_data.numpy())
print("\nEncoded Data:\n", encoded_data.detach().numpy())
print("\nDecoded Data:\n", decoded_data.detach().numpy())
