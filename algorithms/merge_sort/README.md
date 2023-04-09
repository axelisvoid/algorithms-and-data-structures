# Merge Sort

## Explanation

### Notation

$lbound$: The lower bound index of a subarray.
$ubound$: The upper bound index of a subarray.

Merge Sort uses a recursive structure. It divides the original problem of
sorting an array $A[0 : (n - 1)]$ into smaller problems where we have to
sort multiple subarrays $A[ubound: lbound]$. This division is done by
recursing down to smaller and smaller subarrays. The recursion "bottoms
out" when the subarray to be sorted has just one element.
