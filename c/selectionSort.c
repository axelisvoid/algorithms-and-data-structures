#include<stdio.h>
#include<stdlib.h>


/*
 *  SELECTION SORT
 *  --------------
 *
 *  From Wikipedia <https://en.wikipedia.org/wiki/Selection_sort>:
 *
 *  The algorithm divides the input list into two parts: a sorted sublist of items which is built up from left to right
 *  at the front (left) of the list and a sublist of the remaining unsorted items that occupy the rest of the list.
 *  Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds by
 *  finding the smallest (or largest, depending on sorting order) element in the unsorted sublist, exchanging
 *  (swapping) it with the leftmost unsorted element (putting it in sorted order), and moving the sublist boundaries
 *  one element to the right.
 *
 */


void
selectionSort1(int *arr, int size)
{
  int i = 0;

  while (i < size - 1)
  {
    int key = arr[i];
    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < key)
      {
        int tmp = key;
        key = arr[j];
        arr[j] = tmp;
      }
    }

    arr[i] = key;
    i++;
  }
}


void
selectionSort2(int *arr, int size)
{
  int i = 0;
  for (int i = 0; i < size - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }

    int tmp = arr[i];
    arr[i] = arr[min];
    arr[min] = tmp;
  }
}


int
main(int argc, char *argv[])
{
  int n = argc - 1;
  int *arr = malloc(n * sizeof(int));

  for (int i = 1; i < argc; i++)
    arr[i - 1] = atoi(argv[i]);

  selectionSort1(arr, n);
  // selectionSort2(arr, n);
  
  free(arr);
  return 0;
}
