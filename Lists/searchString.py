names = ['saad', 'ahmad', 'ali']


def searchName(input):
    if input in names:  # compare input with each name in names list
        index = names.index(input)
        print(index)
    else:
        print("name not present")


def main():
    name = input("Enter name to search: ")
    searchName(name)


main()
