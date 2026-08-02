#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

// Helper function to add two matrices
Matrix addMatrices(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Helper function to subtract two matrices
Matrix subtractMatrices(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

// Strassen's algorithm
Matrix strassenMultiply(const Matrix &A, const Matrix &B) {
    int n = A.size();

    // Base case: single element
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));
    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    // Divide matrices into quadrants
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Compute the 7 products
    Matrix P1 = strassenMultiply(A11, subtractMatrices(B12, B22));
    Matrix P2 = strassenMultiply(addMatrices(A11, A12), B22);
    Matrix P3 = strassenMultiply(addMatrices(A21, A22), B11);
    Matrix P4 = strassenMultiply(A22, subtractMatrices(B21, B11));
    Matrix P5 = strassenMultiply(addMatrices(A11, A22), addMatrices(B11, B22));
    Matrix P6 = strassenMultiply(subtractMatrices(A12, A22), addMatrices(B21, B22));
    Matrix P7 = strassenMultiply(subtractMatrices(A11, A21), addMatrices(B11, B12));

    // Combine results into final matrix
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            C[i][j + newSize] = P1[i][j] + P2[i][j];
            C[i + newSize][j] = P3[i][j] + P4[i][j];
            C[i + newSize][j + newSize] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const Matrix &matrix) {
    for (const auto &row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrices (power of 2): ";
    cin >> n;

    Matrix A(n, vector<int>(n));
    Matrix B(n, vector<int>(n));

    cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    Matrix result = strassenMultiply(A, B);

    cout << "Resultant matrix:\n";
    printMatrix(result);

    return 0;
}
