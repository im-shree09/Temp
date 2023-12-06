from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Protocol.KDF import PBKDF2
from Crypto.Util.Padding import pad, unpad
from base64 import b64encode, b64decode

def get_aes_key(password, salt):
    key = PBKDF2(password, salt, dkLen=32, count=1000000, hmac_hash_module=None)
    return key

def encrypt_text(plaintext, key):
    iv = get_random_bytes(16)
    cipher = AES.new(key, AES.MODE_CBC, iv)
    
    ciphertext = b""
    last_block = iv
    
    for i in range(0, len(plaintext), AES.block_size):
        block = plaintext[i:i+AES.block_size]
        xor_block = bytes(x ^ y for x, y in zip(block, last_block))
        encrypted_block = cipher.encrypt(xor_block)
        ciphertext += encrypted_block
        last_block = encrypted_block

    return iv + ciphertext

def decrypt_text(ciphertext, key):
    iv = ciphertext[:16]
    ciphertext = ciphertext[16:]
    cipher = AES.new(key, AES.MODE_CBC, iv)
    
    plaintext = b""
    last_block = iv

    for i in range(0, len(ciphertext), AES.block_size):
        block = ciphertext[i:i+AES.block_size]
        decrypted_block = cipher.decrypt(block)
        plaintext_block = bytes(x ^ y for x, y in zip(decrypted_block, last_block))
        plaintext += plaintext_block
        last_block = block

    return unpad(plaintext, AES.block_size).decode()

# Get user input
print("_________________________________________________________________")
print("Let's Explore Cybersecurity -- AES  Algorithm")
print("_________________________________________________________________")
plaintext = input("Enter the text for encryption : ")
password = input("Enter the Key : ")
salt = get_random_bytes(16)

# Generate AES key
key = get_aes_key(password.encode(), salt)

# Encrypt the text
ciphertext = encrypt_text(plaintext.encode(), key)
ciphertext_base64 = b64encode(ciphertext).decode()

print("_________________________________________________________________")
print("Encryption Steps:")
print(f"Salt (Base64): {b64encode(salt).decode()}")
print(f"Initialization Vector (IV, Base64): {b64encode(ciphertext[:16]).decode()}")
print(f"Ciphertext (Base64): {ciphertext_base64}")

print("_________________________________________________________________")


