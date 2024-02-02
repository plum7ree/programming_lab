

# 1. svd
import numpy as np

A = np.array([[1,2], [3,4], [5,6]])

# U, V : unitary matrix. conjugate transpose is inverse matrix. If real number matrix, then also orthogonal.
# Sigma : diagonal matrix, singular values
# which algorithm np.linalg.svd uses householder, QR.
U, Sigma, Vt = np.linalg.svd(A)



