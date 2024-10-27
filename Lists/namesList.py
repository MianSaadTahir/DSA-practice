# add remove and show names in a list

studentsList = []


def addStudent(name):
    studentsList.append(name)
    print(f"{name} has been added")


def removeStudent(name):
    if name in studentsList:
        studentsList.remove(name)
        print(f"{name} has been removed")
    else:
        print(f"{name} not found")


def displayStudents(studentsList):
    if studentsList:
        for student in studentsList:
            print(student)
    else:
        print("no students")


def main():
    while True:
        print("1. Add")
        print("2. Remove")
        print("3. Display")
        print("4. exit")

        choice = input("Enter your choice")

        if choice == "1":
            name = input("Enter name:")
            addStudent(name)
        elif choice == "2":
            name = input("Enter name:")
            removeStudent(name)
        elif choice == "3":
            displayStudents(studentsList)

        elif choice == "4":
            break

        else:
            print("Enter correct choice")


main()
