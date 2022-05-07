#include<stdio.h>
#include<stdlib.h>


void
bubbleSort1(int *arr, int size)
{
  int i, j, tmp;

  for (i = 0; i < size; i++)
  {
    for (j = size - 1; j > i; j--)
    {
      if (arr[j] < arr[j - 1])
      {
        tmp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = tmp;
      }
    }
  }
}


void
bubbleSort2(int *arr, int size)
{
  int i, j, tmp;

  for(i = 0; i < size; i++)
  {
    for (j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}


int
main(int argc, char *argv[])
{
  if (argc == 1)
    return 1;

  int n = argc - 1;
  int *arr = malloc(n * sizeof(int));

  for (int i = 1; i < argc; i++)
    arr[i - 1] = atoi(argv[i]);

  // bubbleSort1(arr, n);
  bubbleSort2(arr, n);

  for (int i = 0; i < n; i++)
    printf("%i, ", arr[i]);

  free(arr);
  return 0;
}
