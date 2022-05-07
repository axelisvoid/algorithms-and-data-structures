#include<stdio.h>
#include<stdlib.h>


/*  
 *  @brief:        Find the position in the array of a given value (if it exists) by looking at subarrays of
 *                 smaller size in a iterative manner.
 *
 *  @param arr:    Sorted array where the value to-be-found is believed to exist.
 *  @param ubound: The upper bound of the subarray where the search is currently taking place.
 *  @param val:    The value to-be-found.
 *
 *  @return int:   The position of the value specified.
 */
int
binarySearchIter(int *arr, int ubound, int val)
{
  int lbound = 0;
  while (lbound >= 0 && lbound <= ubound)
  {
    int midp = (lbound + ubound) / 2;

    if   (arr[midp] == val) return midp + 1;
    if   (arr[midp] > val)  ubound = midp - 1;
    else                    lbound = midp + 1;
  }
}


/*  
 *  @brief:        Find the position in the array of a given value (if it exists) by looking at subarrays of
 *                 smaller size in a recursive manner. 
 *
 *  @param arr:    Sorted array where the value to-be-found is believed to exist.
 *  @param ubound: The upper bound of the subarray where the search is currently taking place.
 *  @param val:    The value to-be-found.
 *
 *  @return int:   The position of the value specified.
 */
int
binarySearchRecur(int *arr, int ubound, int val)
{
  int lbound = 0;
  int midp = (ubound + lbound) / 2;

  if (arr[midp] == val) return midp + 1;

  // if value is smaller than the one at mid, go left.
  // we check up until (size-1) because the actual midpoint value was already checked in the previous if statement.
  if (arr[midp] > val) return (arr, lbound, midp - 1, val);

  // if the value is bigger than the one at mid, go right
  return (arr, midp + 1, ubound, val);
}


int
main(int argc, char *argv[])
{
  int n = argc - 1;                       // Exclude the program name from the args.
  int *arr = malloc(n * sizeof(int));

  for (int i = 1; i < argc; i++)
    arr[i - 1] = atoi(argv[i]);

  int valToFind;

  printf("Enter an integer to find: ");
  scanf("%d", &valToFind);

  // int position = binarySearchIter(arr, n, valToFind);
  int position = binarySearchRecur(arr, n, valToFind);

  printf("The position is: %i\n", position);

  free(arr);
  return 0;
}
