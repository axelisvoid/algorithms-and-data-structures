#include<stdio.h>
#include<stdlib.h>


void bubble_sort(int *arr, int size) {
    int i, j, tmp;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}


int main(int argc, char *argv[]) {
    int n = argc - 1;
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char *endPtr;
        arr[i] = strtol(argv[i + 1], &endPtr, 10);
    }

    bubble_sort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%i, ", arr[i]);

    free(arr);
    return 0;
}
