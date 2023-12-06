import random
import math
from sympy import isprime, nextprime

# Generate two large prime numbers
def generate_large_prime(bits):
    while True:
        num = random.getrandbits(bits)
        if isprime(num):
            return num

bits = 100  # Number of bits for the prime numbers
p = generate_large_prime(bits)
q = generate_large_prime(bits)

# Compute n (the modulus)
n = p * q

# Compute the totient (Euler's totient function)
phi = (p - 1) * (q - 1)

# Choose a public exponent (e) - commonly 65537 (2^16 + 1)
e = 65537

# Calculate the private exponent (d) using modular multiplicative inverse
def mod_inverse(a, m):
    m0, x0, x1 = m, 0, 1
    while a > 1:
        q = a // m
        m, a = a % m, m
        x0, x1 = x1 - q * x0, x0
    return x1 % m0

d = mod_inverse(e, phi)

# Public key: (e, n)
# Private key: (d, n)

# Message to encrypt
message = 42

# Encrypt the message
cipher_text = pow(message, e, n)

# Decrypt the message
decrypted_message = pow(cipher_text, d, n)

print("Original Message:", message)
print("Encrypted Message:", cipher_text)
print("Decrypted Message:", decrypted_message)
