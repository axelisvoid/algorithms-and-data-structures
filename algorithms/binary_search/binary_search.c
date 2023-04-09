#include<stdio.h>
#include<stdlib.h>


int binary_search(int *arr, int ubound, int val) {
    int lbound = 0;

    while (lbound >= 0 && lbound <= ubound) {
        int midpoint = (lbound + ubound) / 2;

        if (arr[midpoint] == val) {
            return midpoint + 1;
        }

        if (arr[midpoint] > val) {
            ubound = midpoint - 1;
        }
        else {
            lbound = midpoint + 1;
        }
    }
    return -1;
}


int binary_search_recursive(int *arr, int lbound, int ubound, int val) {
    int midpoint = (ubound + lbound) / 2;
    if (arr[midpoint] == val) {
        return midpoint + 1;
    }
    if (arr[midpoint] > val) {
        return binary_search_recursive(arr, lbound, midpoint - 1, val);
    }
    return binary_search_recursive(arr, midpoint + 1, ubound, val);
}


int main(int argc, char *argv[]) {
    int n = argc - 1;
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char *endPtr;
        arr[i] = strtol(argv[i + 1], &endPtr, 10);
    }

    int valToFind;
    printf("Enter an integer to find: ");
    scanf("%d", &valToFind);

    // int position = binary_search(arr, n, valToFind);
    int position = binary_search_recursive(
        arr, 0, n, valToFind
    );

    if (position == -1) {
        return 1;
    }

    printf("The position is: %i\n", position);

    free(arr);
    return 0;
}
