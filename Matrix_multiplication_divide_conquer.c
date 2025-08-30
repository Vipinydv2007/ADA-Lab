#include <stdio.h>
#include <stdlib.h>

// Function to allocate a 2D matrix
int** allocateMatrix(int n) {
    int** mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        mat[i] = (int*)malloc(n * sizeof(int));
    return mat;
}

// Function to free a 2D matrix
void freeMatrix(int** mat, int n) {
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

// Function to add two matrices
void addMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Recursive Divide & Conquer Matrix Multiplication
void MMult(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int m = n / 2;

    // Allocate submatrices
    int **A11 = allocateMatrix(m), **A12 = allocateMatrix(m), **A21 = allocateMatrix(m), **A22 = allocateMatrix(m);
    int **B11 = allocateMatrix(m), **B12 = allocateMatrix(m), **B21 = allocateMatrix(m), **B22 = allocateMatrix(m);
    int **C11 = allocateMatrix(m), **C12 = allocateMatrix(m), **C21 = allocateMatrix(m), **C22 = allocateMatrix(m);
    int **X1 = allocateMatrix(m), **X2 = allocateMatrix(m), **X3 = allocateMatrix(m), **X4 = allocateMatrix(m);
    int **X5 = allocateMatrix(m), **X6 = allocateMatrix(m), **X7 = allocateMatrix(m), **X8 = allocateMatrix(m);

    // Divide A and B into submatrices
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j];
            A22[i][j] = A[i + m][j + m];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + m];
            B21[i][j] = B[i + m][j];
            B22[i][j] = B[i + m][j + m];
        }

    // Recursive calls
    MMult(A11, B11, X1, m);
    MMult(A12, B21, X2, m);
    MMult(A11, B12, X3, m);
    MMult(A12, B22, X4, m);
    MMult(A21, B11, X5, m);
    MMult(A22, B21, X6, m);
    MMult(A21, B12, X7, m);
    MMult(A22, B22, X8, m);

    // Combine results
    addMatrix(X1, X2, C11, m);
    addMatrix(X3, X4, C12, m);
    addMatrix(X5, X6, C21, m);
    addMatrix(X7, X8, C22, m);

    // Combine C11, C12, C21, C22 into C
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }

    // Free all submatrices
    freeMatrix(A11, m); freeMatrix(A12, m); freeMatrix(A21, m); freeMatrix(A22, m);
    freeMatrix(B11, m); freeMatrix(B12, m); freeMatrix(B21, m); freeMatrix(B22, m);
    freeMatrix(C11, m); freeMatrix(C12, m); freeMatrix(C21, m); freeMatrix(C22, m);
    freeMatrix(X1, m); freeMatrix(X2, m); freeMatrix(X3, m); freeMatrix(X4, m);
    freeMatrix(X5, m); freeMatrix(X6, m); freeMatrix(X7, m); freeMatrix(X8, m);
}

// Function to print a matrix
void printMatrix(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d ", mat[i][j]);
        printf("\n");
    }
}

int main() {
    int n = 4; // Power of 2
    int** A = allocateMatrix(n);
    int** B = allocateMatrix(n);
    int** C = allocateMatrix(n);

    // Input Matrix A
    printf("Enter elements of 4x4 Matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("Enter element A[%d][%d]: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }

    // Input Matrix B
    printf("Enter elements of 4x4 Matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("Enter element B[%d][%d]: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }

    // Multiply matrices
    MMult(A, B, C, n);

    // Output Result
    printf("\nResult Matrix C (A x B):\n");
    printMatrix(C, n);

    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);

    return 0;
}