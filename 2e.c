#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            // Stop if no swaps happened (array already sorted)
            break;
        }
    }
}

int main() {
    int n_values[] = {1000, 3000, 6000, 10000, 15000, 20000, 25000};
    int num_tests = sizeof(n_values) / sizeof(n_values[0]);

    srand(time(NULL));

    for (int i = 0; i < num_tests; i++) {
        int n = n_values[i];
        int *arr = (int*)malloc(n * sizeof(int));

        // Fill array with random numbers
        for (int j = 0; j < n; j++)
            arr[j] = rand();

        // Measure time taken by Bubble Sort
        clock_t start = clock();
        bubbleSort(arr, n);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Input size: %d, Time taken: %lf seconds\n", n, time_taken);

        free(arr);
    }

    return 0;
}