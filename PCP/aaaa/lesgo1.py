def digicount(n):
    if n==0:
        return 0 
    return 1 + digicount(n//10)
print(digicount(12345))