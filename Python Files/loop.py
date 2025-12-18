for i in range(1, 11):
    print(i, end=" ")

n = 5
total = 0
for i in range(1, n + 1):
    total += i
print("Sum of first", n, "natural numbers is:", total)

num = 7
for i in range(1, 11):
    print(f"{num} × {i} = {num * i}")

n = 5
fact = 1
for i in range(1, n + 1):
    fact *= i
print(f"Factorial of {n} is {fact}")

rows = 5
for i in range(1, rows + 1):
    print("*" * i)

nums = [10, 20, 30, 40]
total = 0
for num in nums:
    total += num
print("Sum of entered numbers is:", total)

for i in range(2, 101, 2):
    print(i, end=" ")

n = 8
a, b = 0, 1
for i in range(n):
    print(a, end=" ")
    a, b = b, a + b

n = int(input("Enter N: "))
i = 1
total = 0
while i <= n:
    total += i
    i += 1
print("Sum =", total)

n = int(input("Enter number: "))
i = 1
while i <= 10:
    print(f"{n} x {i} = {n*i}")
    i += 1

n = int(input("Enter number: "))
fact = 1
i = 1
while i <= n:
    fact *= i
    i += 1
print("Factorial =", fact)

i = 2
while i <= 100:
    print(i, end=" ")
    i += 2

n = int(input("Enter number of terms: "))
a, b = 0, 1
i = 1
while i <= n:
    print(a, end=" ")
    a, b = b, a + b
    i += 1

n = int(input("Enter number: "))
rev = 0
while n > 0:
    digit = n % 10
    rev = rev * 10 + digit
    n //= 10
print("Reverse =", rev)

n = int(input("Enter number: "))
count = 0
while n > 0:
    n //= 10
    count += 1
print("Digits =", count)

n = int(input("Enter number: "))
s = 0
while n > 0:
    s += n % 10
    n //= 10
print("Sum of digits =", s)

n = int(input("Enter number: "))
temp = n
s = 0
while temp > 0:
    digit = temp % 10
    s += digit ** 3
    temp //= 10
if s == n:
    print("Armstrong Number")
else:
    print("Not Armstrong")










