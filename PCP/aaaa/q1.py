def solve_binomial_coefficient(r, c):
    """
    Computes C(r, c) modulo 10^9 + 7 using pre-computed factorials 
    and modular inverse via Fermat's Little Theorem.
    """
    MOD = 10**9 + 7
    MAX_R = 10**5

    # 1. Modular Exponentiation (a^b % m)
    def power(a, b, m):
        res = 1
        a %= m
        while b > 0:
            if b % 2 == 1:
                res = (res * a) % m
            a = (a * a) % m
            b //= 2
        return res

    # 2. Modular Inverse (Fermat's Little Theorem: n^(m-2) % m)
    def modInverse(n, m):
        return power(n, m - 2, m)

    # 3. Pre-compute factorials up to MAX_R
    # fact[i] stores i! % MOD
    fact = [1] * (MAX_R + 1)
    for i in range(2, MAX_R + 1):
        fact[i] = (fact[i - 1] * i) % MOD

    # 4. C(r, c) calculation
    if c < 0 or c > r or r > MAX_R:
        return 0
    
    if c == 0 or c == r:
        return 1
    
    # Optimization: C(r, c) = C(r, r - c)
    if c > r // 2:
        c = r - c 

    # C(r, c) = r! * (c!)^{-1} * ((r-c)! )^{-1} mod P
    numerator = fact[r]
    denominator_c = fact[c]
    denominator_r_c = fact[r - c]

    # Calculate (c!)^{-1} and ((r-c)! )^{-1}
    inv_c = modInverse(denominator_c, MOD)
    inv_r_c = modInverse(denominator_r_c, MOD)

    # Combine: r! * inv(c!) * inv((r-c)!)
    result = (numerator * inv_c) % MOD
    result = (result * inv_r_c) % MOD
    return result

# --- Execution Block ---
# I need your input for r and c to execute this function.
# Example: If r=5 and c=2 (C(5, 2) = 10)
# print(solve_binomial_coefficient(5, 2))
