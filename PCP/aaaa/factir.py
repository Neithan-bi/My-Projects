import math
n = int(input("Enter a number: "))
print("Factors:")
for i in range(1, n + 1):
    if n % i == 0:
        print(i)
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
gcd = math.gcd(a, b)
print(f"The GCD of {a} and {b} is {gcd}.")
def GCD(a,b):
    while b:
        a, b = b, a % b
    return a  
print("GCD of", a, "and", b, "is", GCD(a, b))
def LCM(a, b):
    return (a * b) / GCD(a, b)
print(f"The LCM of {a} and {b} is {LCM(a, b)}.")
def prime(k):
    if k <= 1:
        return False
    for i in range(2, int(math.sqrt(k))):
        if k % i == 0:
            return False
    return True
k = int(input("Enter a number to check if it's prime: "))
if prime(k):
    print(f"{k} is a prime number.")
else:
    print(f"{k} is not a prime number.")

for i in range(2, int(math.sqrt(k))): ]\
        if k % i == 0:
            print()

