from random import randint

def binary_search(arr: list[int], ubound: int, value: int):
    lbound = 0

    while lbound >= 0 and lbound <= ubound:
        midpoint = int((lbound + ubound) / 2)
        if arr[midpoint] == value:
            return midpoint + 1
            
        if arr[midpoint] > value:
            ubound = midpoint - 1
        else:
            lbound = midpoint + 1

    return -1


def binary_search_recursive(
    arr: list[int], lbound: int, ubound: int, value: int,
):
    midpoint = int((lbound + ubound) / 2)
    if arr[midpoint] == value:
        return midpoint + 1
    if arr[midpoint] > value:
        return binary_search_recursive(arr, lbound, midpoint - 1, value)
    return binary_search_recursive(arr, midpoint + 1, ubound, value)


def main():
    arr = sorted([randint(0, 100) for _ in range(10)])
    value_to_find = randint(0, 100)

    found_index = binary_search(arr, len(arr) - 1, value_to_find)
    # uncomment the following line for the recursive version
    # binary_search_recursive(arr, 0, value_to_find)
    print(f"The array is: {arr}")
    print(f"The value to find is: {value_to_find}")
    print(f"Found value at position: {found_index}")


if __name__ == "__main__":
    main()
