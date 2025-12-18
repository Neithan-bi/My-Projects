try:
    re = 10/0
except ZeroDivisionError as e:
    print("Divided by zero error")
    num = intput("Enter a number: ")
    print(num)
except Exception as e:
    print("Some other error")
    num = int("hello")
    print(num)
