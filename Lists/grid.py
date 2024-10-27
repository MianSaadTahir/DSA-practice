# 2d grid operations

grid = []


def addRow(row):
    grid.append(row)

# add each element from column to end of each row


def addCol(col):
    for i in range(len(grid)):
        # add 0 if no more elements in column to maintain symmetry
        grid[i].append(col[i] if i < len(col) else 0)


def displayGrid():
    # print each row in grid
    for row in grid:
        print(row)


def sumGrid():
    return sum(sum(row)for row in grid)


addRow([1, 2, 3])
addRow([4, 5, 6])
addCol([9, 9, 9])


displayGrid()

print(sumGrid())
