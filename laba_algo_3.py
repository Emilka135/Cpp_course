def exponential_search(arr, target, start_idx):
    if arr[start_idx] == target:
        return start_idx
    
    index = 1
    while start_idx + index < len(arr) and arr[start_idx + index] <= target:
        index *= 2

    left = start_idx + index // 2
    right = min(start_idx + index, len(arr) - 1)
    
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1


def has_common_element_exponential(arr1, arr2):
    if not arr1 or not arr2:
        return False
    
    smaller_arr = arr1 if len(arr1) <= len(arr2) else arr2
    larger_arr = arr2 if len(arr1) <= len(arr2) else arr1
    
    for element in smaller_arr:
        if exponential_search(larger_arr, element, 0) != -1:
            return True
    
    return False

arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))
print(has_common_element_exponential(arr1, arr2))