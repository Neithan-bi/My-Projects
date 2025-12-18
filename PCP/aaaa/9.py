def power(base, exp, mod):
    result = 1
    base = base % mod  
    
    while exp > 0:
        if exp & 1:  
            result = (result * base) % mod
        base = (base * base) % mod
        exp >>= 1
    return result

# Example
print(power(3, 13, 17))  # Output: 12
