# import socket

# client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# client_socket.connect(('localhost', 12345))

# # Receive prime and base
# prime = int(client_socket.recv(1024).decode())
# base = int(client_socket.recv(1024).decode())

# # Generate and send the public key
# private_key = 3  # You can choose any private key
# public_key = pow(base, private_key, prime)
# client_socket.send(str(public_key).encode())

# # Receive the server's public key
# server_public_key = int(client_socket.recv(1024).decode())

# # Calculate the shared secret
# shared_secret = pow(server_public_key, private_key, prime)
# print("Shared Secret:", shared_secret)

# client_socket.close()

import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 12345))

# Receive prime and base
prime = int(client_socket.recv(1024).decode())
base = int(client_socket.recv(1024).decode())

# Generate and send the public key
private_key = 3  # You can choose any private key
public_key = pow(base, private_key, prime)
client_socket.send(str(public_key).encode())

# Receive the server's public key
server_public_key = int(client_socket.recv(1024).decode())

# Calculate the shared secret
shared_secret = pow(server_public_key, private_key, prime)
print("Shared Secret:", shared_secret)

client_socket.close()
