"""INSERTION-SORT
 
   INSERTION-SORT takes as a parameter an array A[1...n] containing a sequence of length n
   that is to be sorted.  The algorithm sorts the input number *in place*: it rearranges the
   numbers within the array A, with at most a constant number of them stored outside the
   array at any time.  The input array A contains the sorted output sequence when the
   INSERTION-SORT procedure isfinished.
"""


def insertion_sort(arr: list) -> None:

  for i in range(1, len(arr)):
    key = arr[i]
    j = i - 1

    while j >= 0 and arr[j] > key:
      arr[j + 1] = arr[j]
      j -= 1
    
    arr[j + 1] = key


def main() -> None:

  A = [3, 4, 9, 0, 1, 3, 2]
  insertion_sort(A)
  print(A)


if __name__ == "__main__":
  main()
