#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
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
        // Measure time
        clock_t start = clock();
        selectionSort(arr, n);
        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Input size: %d, Time taken: %lf seconds\n", n, time_taken);
        free(arr);
    }
    return 0;
}