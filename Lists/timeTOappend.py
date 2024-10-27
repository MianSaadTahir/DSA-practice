# calculate time to append integers in a list

import time

numbers = []

for i in range(1, 101):
    start = time.time()
    numbers.append(i)
    end = time.time()
    append_time = end-start
    # convert appending time to float
    print(f"Appending {i} took {append_time:.10f}seconds")
