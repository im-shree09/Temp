import socket
import random
import math

# Function to calculate (base^exp) % mod efficiently
def mod_exp(base, exp, mod):
    if exp == 0:
        return 1
    if exp % 2 == 0:
        temp = mod_exp(base, exp // 2, mod)
        return (temp * temp) % mod
    else:
        temp = mod_exp(base, exp - 1, mod)
        return (base * temp) % mod

# Function to generate a random prime number
def generate_prime(bits=1024):
    while True:
        num = random.getrandbits(bits)
        if num % 2 != 0 and all(num % i != 0 for i in range(3, int(math.isqrt(num)) + 1, 2)):
            return num

# Function to perform Diffie-Hellman key exchange
def diffie_hellman(sock):
    # Generate and share a large prime number and a base
    prime = generate_prime()
    base = random.randint(2, prime - 1)
    sock.send(str(prime).encode())
    sock.send(str(base).encode())

    # Choose a private key
    private_key = random.randint(2, prime - 2)
    public_key = mod_exp(base, private_key, prime)
    sock.send(str(public_key).encode())

    # Receive the other party's public key
    other_public_key = int(sock.recv(1024).decode())

    # Calculate the shared secret
    shared_secret = mod_exp(other_public_key, private_key, prime)
    return shared_secret

# Create a socket and listen for connections
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 12345))
server_socket.listen(1)

print("Waiting for a connection...")
client_socket, client_address = server_socket.accept()

print("Connected to:", client_address)

# Perform Diffie-Hellman key exchange
shared_secret = diffie_hellman(client_socket)
print("Shared Secret:", shared_secret)

# Close the sockets
client_socket.close()
server_socket.close()
