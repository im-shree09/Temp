import gmpy2

def extended_gcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = extended_gcd(b % a, a)
        return (g, y - (b // a) * x, x)

a = gmpy2.mpz(485)
b = gmpy2.mpz(300)

g, x, y = extended_gcd(a, b)

print(f"Euclidean GCD of {a} and {b} is: {g}")
print(f"Extended Euclidean: {a} * {x} + {b} * {y} = {g}")
