def encrypt(text, key):
    # Remove spaces and convert text to uppercase
    text = text.replace(" ", "").upper()
    
    # Calculate the number of rows needed
    rows = len(text) // len(key)
    if len(text) % len(key) != 0:
        rows += 1
    
    # Pad the text with extra characters to make it evenly divisible
    padding = rows * len(key) - len(text)
    text += "X" * padding
    
    # Create a matrix for the plaintext
    matrix = [list(text[i:i+len(key)]) for i in range(0, len(text), len(key))]
    print("Matrix: ",matrix)
    # Create a list to store the encrypted columns
    encrypted_columns = [''] * len(key)
    
    # Rearrange columns according to the key
    for idx in range(len(key)):
        col_idx = key.index(idx + 1)
        encrypted_columns[col_idx] = ''.join(row[idx] for row in matrix)
    
    # Generate the ciphertext by reading rows
    ciphertext = ''.join(encrypted_columns)
    return ciphertext

def decrypt(ciphertext, key):
    # Calculate the number of rows needed
    rows = len(ciphertext) // len(key)
    
    # Create a matrix for the ciphertext
    matrix = [list(ciphertext[i:i+rows]) for i in range(0, len(ciphertext), rows)]
    
    # Create a list to store the decrypted rows
    decrypted_rows = [''] * rows
    
    # Rearrange rows according to the key
    for idx in range(len(key)):
        row_idx = key.index(idx + 1)
        for i in range(rows):
            decrypted_rows[i] += matrix[row_idx][i]
    
    # Generate the plaintext by reading rows
    plaintext = ''.join(decrypted_rows)
    return plaintext


# plaintext = "HELLO Shree"
# print("Plain Text:", plaintext)
# key = [2, 1, 4, 3] 
# print("Key: ",key) 

plaintext = input("Enter the plaintext: ")
key_str = input("Enter the key (e.g., 2,1,4,3): ")
key = [int(k) for k in key_str.split(',')]

ciphertext = encrypt(plaintext, key)
print("Ciphertext:", ciphertext)

decrypted_text = decrypt(ciphertext, key)
print("Decrypted:", decrypted_text)
