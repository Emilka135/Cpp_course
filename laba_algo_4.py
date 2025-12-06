def binary_search_division_optimized(arr1, arr2):
    if not arr1 or not arr2:
        return False
    
    def binary_search(arr, target):
        left, right = 0, len(arr) - 1
        while left <= right:
            mid = (left + right) // 2
            if arr[mid] == target:
                return True
            elif arr[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False
    
    def divide_and_conquer(start1, end1, start2, end2):
        if start1 > end1 or start2 > end2:
            return False
            
        mid1 = (start1 + end1) // 2
        central_element = arr1[mid1]
        
        if binary_search(arr2[start2:end2+1], central_element):
            return True
            
        if start1 < end1:
            mid_left1 = mid1
            mid_right1 = mid1 + 1
            
            if central_element < arr2[start2]:
                if mid_right1 <= end1:
                    return divide_and_conquer(mid_right1, end1, start2, end2)
            elif central_element > arr2[end2]:
                if start1 <= mid_left1 - 1:
                    return divide_and_conquer(start1, mid_left1 - 1, start2, end2)
            else:
                left_result = divide_and_conquer(start1, mid_left1, start2, end2)
                if left_result:
                    return True
                right_result = divide_and_conquer(mid_right1, end1, start2, end2)
                return right_result
                
        return False
    
    return divide_and_conquer(0, len(arr1) - 1, 0, len(arr2) - 1)


arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))
print(binary_search_division_optimized(arr1, arr2))