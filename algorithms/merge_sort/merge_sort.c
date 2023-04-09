#include<stdio.h>
#include<stdlib.h>


void merge(int *arr, int lbound, int midpoint, int ubound);


void merge_sort(int *arr, int lbound, int ubound) {
    if (lbound == ubound)
        return;

    int midpoint = (lbound + ubound) / 2;
    merge_sort(arr, lbound, midpoint);
    merge_sort(arr, midpoint + 1, ubound);
    merge(arr, lbound, midpoint, ubound);
}


void merge(int *arr, int lbound, int midpoint, int ubound) {
    int flen = midpoint - lbound + 1;  // length of left-side subarray
    int rlen = ubound - midpoint;      // length of right-side subarray
    int fsubarr[flen], rsubarr[rlen];

    int i, j = 0;
    for (i = 0; i < flen; i++) {
        fsubarr[i] = arr[lbound + i];
    }

    for (j = 0; j < rlen; j++) {
        rsubarr[j] = arr[midpoint + 1 + j];
    }

    i = 0;
    j = 0;
    int k = lbound;

    while (i < flen && j < rlen) {
        if (fsubarr[i] <= rsubarr[j]) {
            arr[k] = fsubarr[i];
            i++;
        } else {
            arr[k] = rsubarr[j];
            j++;
        }
        k++;
    }

    while (i < flen) {
        arr[k] = fsubarr[i];
        i++;
        k++;
    }

    while (j < rlen) {
        arr[k] = rsubarr[j];
        j++;
        k++;
    }
}


int main(int argc, char *argv[]) {
    int n = argc - 1;
    int *arr = malloc(n * sizeof(int));

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        char *endPtr;
        arr[i] = strtol(argv[i + 1], &endPtr, 10);
        printf("%d\t", arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    printf("\nNew array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
}
