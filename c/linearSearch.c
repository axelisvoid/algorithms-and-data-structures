#include<stdio.h>
#include<stdlib.h>


int linearSearch(int *arr, int size, int val)
{
  for (int i = 0; i < size; i++)
    if (arr[i] == val)
      return i + 1;
  return -1;
}



int
main(int argc, char *argv[])
{
  int n = argc - 1;
  int *arr = malloc(n * sizeof(int));

  for (int i = 1; i < argc; i++)
    arr[i - 1] = atoi(argv[i]);

  int valToFind;

  printf("Enter an integer to find: ");
  scanf("%d", &valToFind);

  int position = linearSearch(arr, n, valToFind);
  if (position == -1)
    printf("Value '%i' not found\n", valToFind);
  else
    printf("The position is: %i\n", position);

  free(arr);
  return 0;
}
