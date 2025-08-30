#include <stdio.h>

int main() {
    int A[4][4], B[4][4], C[4][4];
    int i, j, k;

    // Input Matrix A
    printf("Enter elements of 4x4 Matrix A:\n");
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++){
            printf("A[%d][%d]: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }

    // Input Matrix B
    printf("Enter elements of 4x4 Matrix B:\n");
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++){
            printf("B[%d][%d]: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }

    // Initialize Matrix C to 0
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            C[i][j] = 0;

    // Multiply A and B
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            for(k = 0; k < 4; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print Result
    printf("\nResult Matrix C (A x B):\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++)
            printf("%5d ", C[i][j]);
        printf("\n");
    }

    return 0;
}