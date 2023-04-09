def insertion_sort(arr: list[int], size: int) -> None:
    for i in range(1, size):
        key = arr[i]
        j = i - 1

        while (j >= 0 and arr[j] > key):
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


def insertion_sort_recursive(arr: list[int], size: int) -> None:
    bitSize = size - 1
    if size > 1:
        insertion_sort_recursive(arr, bitSize)
    
    key = arr[bitSize]
    j = bitSize - 1

    while (j >= 0 and arr[j] > key):
        arr[j + 1] = arr[j]
        j -= 1
    arr[j + 1] = key


def main():
    from random import randint
    arr = [randint(1, 100) for _ in range(10)]
    print(f"Original array:\n{arr}")

    insertion_sort(arr, len(arr))
    # uncomment the following line for the recursive version of this algorithm
    # insertion_sort_recursive(arr, len(arr))
    print(f"New array:\n{arr}")


if __name__ == "__main__":
    main()
