def mergeSort(arr):
    n = len(arr)
    if n > 1:  # keep dividing uptil one element is left in array, then its already sorted
        mid = n//2
        # make two sub arrays around the midpoint
        left = arr[:mid]
        right = arr[mid:]

        # recursively sort left and right subarrays
        mergeSort(left)
        mergeSort(right)

        # Initialize pointers for left (i), right (j), and merged array (k)
        i = j = k = 0

        # Merge the sorted left and right subarrays back into arr
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                # if left sub array has smaller element place it first in arr
                arr[k] = left[i]
                i += 1
                # other wise place the right subarray element first
            else:
                arr[k] = right[j]
                j += 1
            k += 1  # keep moving ahead in merged array

        # copy remaining elements from left and right sub array to output
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1
    return arr


arr = [4, 2, 8, 9, 1]
output = mergeSort(arr)
print(output)
