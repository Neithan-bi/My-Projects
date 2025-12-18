def add(i,j):
    return i +j 

a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
result = add(a, b)
print(f"The sum of {a} and {b} is {result}.")

def fact(h):
    fac = 1
    for i in range(1, h + 1):
        fac *= i
    return fac

n = int(input("Enter a number to calculate its factorial: "))
factorial_result = fact(n)
print(f"The factorial of {n} is {factorial_result}.")

def fibanooci(n):
    a, b = 0, 1
    count = 0
    while count < n:
        print(a, end=' ')
        a, b = b, a + b
        count += 1
n = int(input("Enter the number of Fibonacci terms to display: "))
fibanooci(n)
print()  

def sumdigits(num):
    total = 0
    while num > 0:
        total += num % 10
        num //= 10
    return total
num = int(input("Enter a number to sum its digits: "))
digit_sum = sumdigits(num)
print(f"The sum of the digits of {num} is {digit_sum}.")

def reversestring(s):
    return s[::-1]
s = input("Enter a string to reverse: ")
res = reversestring(s)
print(f"The reversed string is: {res}")

def palindrome(y):
    return y == y[::-1]
y = input("Enter a string to check if it's a palindrome: ")
if palindrome(y):
    print(f"{y} is a palindrome.")
else:
    print(f"{y} is not a palindrome.")

def maximum(x, y,c):
    return max(x, y, c)
x = int(input("Enter first number: "))
y = int(input("Enter second number: "))
c = int(input("Enter third number: "))
maxvalue = maximum(x, y, c)
print(f"The maximum of {x}, {y}, and {c} is {maxvalue}.")

def multitable(n):
    for i in range(1, 11):
        print(f"{n} x {i} = {n * i}")
n = int(input("Enter a number to display its multiplication table: "))
multitable(n)   

def areacirckle(rad):
    
    pi = 3.14
    return pi * rad * rad
rad = float(input("Enter the radius of the circle: "))
area = areacirckle(rad)
print(f"The area of the circle with radius {rad} is {area}.")




