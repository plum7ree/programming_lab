
// "Learning with Kernels" by Bernhard Schölkopf and Alexander J. Smola. This book provides a deep dive into kernel methods, including Kernel PCA.

// Scikit-learn's documentation on Kernel PCA. Scikit-learn is a popular machine learning library in Python. Although it's not in C++, the mathematical principles, explanations, and examples provided can be valuable. Scikit-learn KernelPCA
// https://scikit-learn.org/stable/modules/generated/sklearn.decomposition.KernelPCA.html
// skikit-learn source code: https://github.com/scikit-learn/scikit-learn/blob/7f9bad99d/sklearn/decomposition/_kernel_pca.py#L32

// Research papers and academic articles on Kernel PCA can also be a good reference. One foundational paper is:

// "Kernel principal component analysis" by Bernhard Schölkopf, Alexander Smola, and Klaus-Robert Müller.

#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

// #include <boost/math/distributions/normal.hpp>

using namespace Eigen;

// RBF (Gaussian) kernel function
MatrixXd rbf_kernel(const MatrixXd& X, double gamma) {
    MatrixXd K(X.rows(), X.rows());
    for (int i = 0; i < X.rows(); i++) {
        for (int j = 0; j < X.rows(); j++) {
            // X.row(i) : Eigen::RowVectorXd 
            // rbf kernel = gamma * || x - center ||^2
            // norm() : calculate L2 norm of vector
            // X,row(i) - X.row(j) : vector subtraction 
            // which is {row(i,0) - row(j,0)), (row(i,1) - row(j,1) ... }?
            double distance = (X.row(i) - X.row(j)).norm();
            K(i, j) = exp(-gamma * distance * distance);
        }
    }
    return K;
}

MatrixXd gaussian_kernel(const MatrixXd& X ) {

}

double linearKernel(const VectorXd& x, const VectorXd& y) {
    return x.dot(y);
}

double polynomialKernel(const VectorXd& x, const VectorXd& y, int d) {
    return pow(x.dot(y) + 1, d);
}

double rbfKernel(const VectorXd& x, const VectorXd& y, double sigma) {
    return exp(-((x - y).squaredNorm()) / (2 * sigma * sigma));
}

double sigmoidKernel(const VectorXd& x, const VectorXd& y, double alpha, double c) {
    return tanh(alpha * x.dot(y) + c);
}

double laplacianKernel(const VectorXd& x, const VectorXd& y, double sigma) {
    return exp(-((x - y).lpNorm<1>()) / sigma);
}

// Kernel PCA
MatrixXd kernelPCA(const MatrixXd& X, double gamma, int n_components) {
    MatrixXd K = rbf_kernel(X, gamma);

    // Center the kernel matrix
    MatrixXd oneN = MatrixXd::Constant(X.rows(), X.rows(), 1.0 / X.rows());
    K = K - oneN * K - K * oneN + oneN * K * oneN;

    // Eigen decomposition
    EigenSolver<MatrixXd> solver(K);
    MatrixXd eigvecs = solver.eigenvectors().real();

    // Sort by eigenvalues and select the top components
    std::vector<int> idx(K.cols());
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&solver](int i1, int i2) {
        return solver.eigenvalues().real()[i1] > solver.eigenvalues().real()[i2];
    });

    MatrixXd components = MatrixXd(n_components, X.rows());
    for (int i = 0; i < n_components; i++) {
        components.row(i) = eigvecs.col(idx[i]).transpose();
    }

    return components;
}

int main() {
    // Generate a dummy dataset
    MatrixXd X(10, 2);
    X <<  1, 2,
          3, 4,
          5, 6,
          7, 8,
          9, 10,
          11, 12,
          13, 14,
          15, 16,
          17, 18,
          19, 20;

    // Apply Kernel PCA
    double gamma = 0.1;
    int n_components = 2;
    MatrixXd transformed = kernelPCA(X, gamma, n_components);

    std::cout << "Transformed Data:\n" << transformed << std::endl;

    return 0;
}