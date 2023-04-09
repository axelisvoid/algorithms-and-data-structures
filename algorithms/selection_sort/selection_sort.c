#include<stdio.h>
#include<stdlib.h>


void selection_sort(int *arr, int size) {
    int i = 0;

    while (i < size - 1) {
        int key = arr[i];
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < key) {
                int tmp = key;
                key = arr[j];
                arr[j] = tmp;
            }
        }
        arr[i] = key;
        i++;
    }
}


void selection_sort_v2(int *arr, int size) {
    int i = 0;
    for (int i = 0; i < size - 1; i++) {
        int key = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[key])
                key = j;
        }

        int tmp = arr[i];
        arr[i] = arr[key];
        arr[key] = tmp;
    }
}


int main(int argc, char *argv[]) {
    int n = argc - 1;
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char *endPtr;
        arr[i] = strtol(argv[i + 1], &endPtr, 10);
    }

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    selection_sort(arr, n);
    // selection_sort_v2(arr, n);

    printf("The new array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    free(arr);
    return 0;
}
