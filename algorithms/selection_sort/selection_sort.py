from random import randint


def selection_sort(arr: list[int]):
    while i < len(arr) - 1:
        key = arr[i]
        for j in range(i + 1, len(arr)):
            if arr[j] > key:
                tmp = key
                key = arr[j]
                arr[j] = tmp

        arr[j] = key
        i += 1


def selection_sort_v2(arr: list[int]):
    for i in range(len(arr) - 1):
        key = i
        for j in range(i + 1, len(arr)):
            if arr[j] < key:
                key = j
        tmp = arr[i]
        arr[i] = arr[key]
        arr[key] = tmp


def main():
    arr = [randint(0, 100) for _ in range(10)]
    print("The original array is:")
    print(arr)

    selection_sort(arr)
    # uncomment the following line for another version
    # selection_sort_v2(arr)

    print("The new array is:")
    print(arr)

if __name__ == "__main__":
    main()
