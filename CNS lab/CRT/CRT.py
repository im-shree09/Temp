def extended_gcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = extended_gcd(b % a, a)
        return (g, y - (b // a) * x, x)

def mod_inverse(a, m):
    g, x, _ = extended_gcd(a, m)
    if g != 1:
        raise ValueError("The modular inverse does not exist.")
    return x % m

def chinese_remainder_theorem(n, a):
    N = 1
    N_i = []
    x_i = []
    b_i = []

    for ni in n:
        N *= ni

    for ni in n:
        N_i.append(N // ni)
        x_i.append(mod_inverse(N_i[-1], ni))

    for i in range(len(n)):
        b_i.append(a[i] * N_i[i] * x_i[i])

    print("Intermediate Steps:")
    for i in range(len(n)):
        print(f"N_{i} = {N_i[i]}, x_{i} = {x_i[i]}, b_{i} = {b_i[i]}")

    result = sum(b_i) % N

    return result

# Input from the user
n = []
a = []

num_congruences = int(input("Enter the number of congruences: "))

for i in range(num_congruences):
    n_i = int(input(f"Enter the modulus (n_{i}): "))
    a_i = int(input(f"Enter the remainder (a_{i}): "))
    n.append(n_i)
    a.append(a_i)

result = chinese_remainder_theorem(n, a)

print("\nSystem of Congruences:")
for i in range(len(n)):
    print(f"x = {a[i]} (mod {n[i]})")

print(f"The solution is x = {result}")
