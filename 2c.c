#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Insertion Sort Function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements greater than key one step ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int n_values[] = {1000, 3000, 6000, 10000, 15000, 20000, 25000};
    int num_tests = sizeof(n_values) / sizeof(n_values[0]);
    srand(time(NULL));
    for (int i = 0; i < num_tests; i++) {
        int n = n_values[i];
        int *arr = (int*)malloc(n * sizeof(int));
        // Generate random numbers
        for (int j = 0; j < n; j++) {
            arr[j] = rand();
        }
        clock_t start = clock();
        insertionSort(arr, n);
        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Input size: %d, Time taken: %lf seconds\n", n, time_taken);
        free(arr);  // free allocated memory
    }
    return 0;
}