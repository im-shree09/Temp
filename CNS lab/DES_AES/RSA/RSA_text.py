from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import padding

# Generate RSA keys
private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048,
)

# Get the public key
public_key = private_key.public_key()

# Text to encrypt (user input)
plaintext = input("Enter the text to encrypt: ").encode('utf-8')

# Encrypt the plaintext using the public key
ciphertext = public_key.encrypt(
    plaintext,
    padding=padding.OAEP(
        mgf=padding.MGF1(algorithm=hashes.SHA256()),
        algorithm=hashes.SHA256(),
        label=None
    )
)

# Print the ciphertext
print("Encrypted message:", ciphertext)

# Decrypt the ciphertext using the private key
decrypted_text = private_key.decrypt(
    ciphertext,
    padding=padding.OAEP(
        mgf=padding.MGF1(algorithm=hashes.SHA256()),
        algorithm=hashes.SHA256(),
        label=None
    )
)

# Convert the decrypted bytes back to text
decrypted_message = decrypted_text.decode('utf-8')

# Print the decrypted message
print("Decrypted message:", decrypted_message)
