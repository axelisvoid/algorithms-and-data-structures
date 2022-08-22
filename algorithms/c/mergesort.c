#include<stdio.h>


void merge(int *array, int lbound, int midpoint, int ubound) {

  int flen = midpoint - lbound + 1;  // length of the left-side subarray
  int rlen = ubound - midpoint;      // length of the right-side subarray

  int fsubarray[flen], rsubarray[rlen];

  int i, j = 0;
  for (i = 0; i < flen; i++)
    fsubarray[i] = array[lbound + i];

  for (j = 0; j < rlen; j++)
    rsubarray[j] = array[midpoint + 1 + j];

  i = 0;
  j = 0;
  int k = lbound;

  while (i < flen && j < rlen) {

    if (fsubarray[i] <= rsubarray[j]) {
      array[k] = fsubarray[i];
      i++;
    } else {
      array[k] = rsubarray[j];
      j++;
    }
    k++;
  }

  // now that we're done with either `fsubarray` or `rsubarray`, add the
  // remaining elements of the subarray that still has unmerged elements

  while (i < flen) {
    array[k] = fsubarray[i];
    i++;
    k++;
  }

  while (j < rlen) {
    array[k] = rsubarray[j];
    j++;
    k++;
  }
  
}

void mergeSort(int *array, int lbound, int ubound) {

  // if zero or one element, we're done!
  if (lbound >= ubound) return;

  int midpoint = (lbound + ubound) / 2;

  mergeSort(array, lbound, midpoint);
  mergeSort(array, midpoint + 1, ubound);

  merge(array, lbound, midpoint, ubound);

}


int main() {

  int unord_array[] = {9, 0, 2, 3, 4, 4, 3, 5};
  int n = sizeof(unord_array)/sizeof(unord_array[0]);

  mergeSort(unord_array, 0, n - 1);

  for (int i = 0; i < n; i++)
    printf("%d, ", unord_array[i]);
}
