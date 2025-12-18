num1 = int(input("Enter value for num1 : "))
num2 = int(input("Enter value for num2 : "))

while (num1!=0 and num2!=0):
    choice = int(input("1 for addition,\n2 for subtraction,\n3 for multiplication,\n4 for division,\n5 for modulus,\n6 for square: "))
    if choice == 1:
        add = num1 + num2
        print("Sum of num1 and num2 is ", add)
        break
    elif choice == 2:
        sub = num1 - num2
        print("Difference of num1 and num2 is ", sub)
        break
    elif choice == 3:
        mul = num1 * num2
        print("Product of num1 and num2 is ", mul)
        break
    elif choice == 4:
        div = num1 / num2
        print("Division of num1 by num2 is ", div)
        break
    elif choice == 5:
        mod = num1 % num2
        print("Modulus of num1 and num2 is ", mod)
        break
    elif choice == 6:
        square_num1 = num1 ** 2
        square_num2 = num2 ** 2
        print("Square of num1 is ", square_num1)
        print("Square of num2 is ", square_num2)
        break
    else:
        print("Invalid choice. Please try again.")
else:
    print("Exiting the calculator as one or both of the numbers is/are zero.")
