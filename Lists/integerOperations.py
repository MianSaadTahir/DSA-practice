numbers = [12, -7, 5, 64, -14, 0, 23, -8]


def operations(numbers):
    # extract positive numbers
    numbers = [num for num in numbers if num >= 0]
    maxValue = max(numbers) if numbers else None
    minValue = min(numbers) if numbers else None
    average = sum(numbers)/len(numbers) if numbers else None

    return numbers, maxValue, minValue, average


positives, maximum, minimum, avg = operations(numbers)


print(f"Non negative list: {positives}")
print(f"Maximum number: {maximum}")
print(f"Minimum number: {minimum}")
print(f"Average of list: {avg}")
