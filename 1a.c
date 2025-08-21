#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear Search function
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  // element found at index i
    }
    return -1; // element not found
}

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Generate random array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    // Take the last element as the key (worst case)
    key = arr[n - 1];

    clock_t start = clock();
    for (int i = 0; i < 1000; i++) {
        int result = linearSearch(arr, n, key);
    }
    clock_t end = clock();

    // Average time taken over 1000 runs
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    printf("Element searched: %d\n", key);
    printf("Time taken for n=%d is %f seconds (averaged over 1000 runs)\n", n, time_taken);

    free(arr);
    return 0;
}