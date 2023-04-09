from random import randint


def merge_sort(arr: list[int], lbound: int, ubound: int):
    if ubound - lbound == 0:
        return

    midpoint = int((lbound + ubound) / 2)

    merge_sort(arr, lbound, midpoint)
    merge_sort(arr, midpoint + 1, ubound)
    merge(arr, lbound, midpoint, ubound)


def merge(arr: list[int], lbound: int, midpoint: int, ubound: int):
    
    flen = midpoint - lbound + 1
    rlen = ubound - midpoint

    fsubarr = [arr[lbound + i] for i in range(flen)]
    rsubarr = [arr[midpoint + 1 + j] for j in range(rlen)]

    i = 0
    j = 0
    k = lbound

    while i < flen and j < rlen:
        if (fsubarr[i] <= rsubarr[j]):
            arr[k] = fsubarr[i]
            i += 1
        else:
            arr[k] = rsubarr[j]
            j += 1
        k += 1

    while i < flen:
        arr[k] = fsubarr[i]
        i += 1
        k += 1

    while j < rlen:
        arr[k] = rsubarr[j]
        j += 1
        k += 1


def main():

    arr = [randint(1, 100) for _ in range(10)]

    print("Original array:")
    print(arr)

    merge_sort(arr, 0, len(arr) - 1)

    print("New array")
    print(arr)


if __name__ == "__main__":
    main()

