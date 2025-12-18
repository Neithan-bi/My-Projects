def find_cth_prime(r, c):
    """
    Finds the c-th prime number (0-indexed) among the integers from 1 to r.
    Uses the Sieve of Eratosthenes for efficiency.
    """
    if r < 2:
        # There are no primes if r is less than 2
        return -1
    
    # 1. Sieve of Eratosthenes Initialization
    # We need to check up to r (10^6)
    is_prime = [True] * (r + 1)
    is_prime[0] = is_prime[1] = False  # 0 and 1 are not prime
    
    # 2. Sieve Calculation
    # Iterate from p=2 up to sqrt(r)
    # 
    for p in range(2, int(r**0.5) + 1):
        if is_prime[p]:
            # If p is prime, mark all its multiples as non-prime
            # Start marking from p*p, as smaller multiples (p*2, p*3, etc.) 
            # would have already been marked by smaller primes.
            for i in range(p * p, r + 1, p):
                is_prime[i] = False
                
    # 3. List Primes
    primes = []
    for num in range(2, r + 1):
        if is_prime[num]:
            primes.append(num)
            
    # Optimization based on constraint: If c is too large, we can stop early
    # The constraint 0 <= c <= 10^5 ensures that if the list is long enough, 
    # we don't need to worry about index c being > r.

    # 4. Lookup
    if c < len(primes):
        # Index c is 0-indexed
        return primes[c]
    else:
        # Fewer than c+1 primes exist
        return -1

# --- Execution Block ---
# I need your input for r and c to execute this function.
# Example: If r=20 and c=4. The primes are [2, 3, 5, 7, 11, 13, 17, 19].
# The 4th prime (0-indexed) is 11.
# print(find_cth_prime(20, 4))