/*
 *  INSERTION-SORT
 *  
 *  INSERTION-SORT takes as a parameter an array A[1...n] containing a sequence of length n
 *  that is to be sorted.  The algorithm sorts the input number *in place*: it rearranges the
 *  numbers within the array A, with at most a constant number of them stored outside the
 *  array at any time.  The input array A contains the sorted output sequence when the
 *  INSERTION-SORT procedure isfinished.
 * 
 */


#include<stdio.h>
#include<stdlib.h>


void
insertionSort(int *arr, int size)
{
  for (int i = 1; i < size; i++)
  {
    int key = arr[i];
    int j = i-1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}


void
insertionSortRecur(int *arr, int size)
{
  int p = size - 1;

  if (size > 1)
    insertionSortRecur(arr, p);

  int key = arr[p];
  int j = p-1;

  while (j >= 0 && arr[j] > key)
  {
    arr[j+1] = arr[j];
    j--;
  }
  
  arr[j+1] = key;
}


// TODO: Insertion sort mixed with binary search
// TODO: Insertion sort mixed with merge sort


int
main(int argc, char *argv[])
{
  if (argc == 1)
    return 1;

  int n = argc - 1;
  int *arr = malloc(n * sizeof(int));

  for (int i = 1; i < argc; i++)
    arr[i - 1] = atoi(argv[i]);

  insertionSort(arr, n);
  // insertionSortRecur(arr, n);

  for (int i = 0; i < n; i++)
    printf("%i, ", arr[i]);
}
