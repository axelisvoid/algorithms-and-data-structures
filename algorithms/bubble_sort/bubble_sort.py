from random import randint


def bubble_sort(arr: list[int]) -> int:
    i, j, tmp = 0, 0, 0

    for i in range(len(arr)):
        for j in range(0, len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                tmp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = tmp


def main():

    arr = [randint(0, 100) for _ in range(10)]
    print("Original array:")
    print(arr)
    bubble_sort(arr)
    print(arr)


if __name__ == "__main__":
    main()
