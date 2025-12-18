n = int(input("Enter a number: "))

for i in range(1, n + 1):
    if n % i == 0:
        print(i)
        li[i] = i
print(f"The divisors of {n} are: {li[1:n+1]}")


