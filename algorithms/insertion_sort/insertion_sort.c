#include<stdio.h>
#include<stdlib.h>


void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void insertion_sort_recursive(int *arr, int size) {
    int bitSize = size - 1;
    if (size > 1) {
        insertion_sort_recursive(arr, bitSize);
    }

    int key = arr[bitSize];
    int j = bitSize - 1;

    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}


int main(int argc, char *argv[]) {
    int n = argc - 1;
    int *arr = malloc(n * sizeof(int));

    for (int i = 1; i < n; i++) {
        char *endPtr;
        arr[i - 1] = strtol(argv[i], &endPtr, 10);
    }

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d,\t", arr[i]);
    }

    insertion_sort(arr, n);
    // Uncomment the following line for the recursive version of this algorithm
    // insertion_sort_recursive

    printf("New array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d,\t", arr[i]);
    }
}
