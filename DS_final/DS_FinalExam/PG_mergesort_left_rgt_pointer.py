def merge_sort_counting_inversions(arr):
    if len(arr) <= 1:
        return arr, 0
    else:
        mid = len(arr) // 2
        left, left_inversions = merge_sort_counting_inversions(arr[:mid])
        right, right_inversions = merge_sort_counting_inversions(arr[mid:])
        merged, split_inversions = merge_counting_inversions(left, right)
        total_inversions = left_inversions + right_inversions + split_inversions
        return merged, total_inversions

def merge_counting_inversions(left, right):
    result = []
    i, j = 0, 0
    inversions = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            # i is no switch times, now += the rest left
            inversions += len(left) - i
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result, inversions

# Read input
n = int(input().strip())
plates = input().strip().split()

# Count inversions
_, inversions = merge_sort_counting_inversions(plates)

# Print the number of exchanges (inversions)
print(inversions)
