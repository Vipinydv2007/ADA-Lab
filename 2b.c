#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Partition function using the last element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int n_values[] = {1000, 3000, 6000, 10000, 15000, 20000, 25000};
    int num_tests = sizeof(n_values) / sizeof(n_values[0]);
    srand(time(NULL));
    for (int i = 0; i < num_tests; i++) {
        int n = n_values[i];
        int *arr = (int*)malloc(n * sizeof(int));
        // generate random numbers
        for (int j = 0; j < n; j++) {
            arr[j] = rand();
        }
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Input size: %d, Time taken: %lf seconds\n", n, time_taken);
        free(arr);  // free memory after use
    }
    return 0;
}