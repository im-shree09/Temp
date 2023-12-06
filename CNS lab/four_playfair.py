# def create_matrix(key):
#     matrix = []
#     key = key.replace(' ', '').upper()  # Added parentheses to upper()
#     key += 'ABCDEFGHIKLMNOPQRSTUVWXYZ'
#     for char in key:
#         if char not in matrix:
#             matrix.append(char)
#     return matrix

# def prep_input(plaintext):
#     plaintext = plaintext.replace(' ', '').upper()
#     plaintext = plaintext.replace('J', 'I')

#     # Insert 'X' between repeated letters and add a trailing 'X' if the text length is odd
#     i = 0
#     while i < len(plaintext) - 1:  # Changed 'text' to 'plaintext'
#         if plaintext[i] == plaintext[i + 1]:
#             plaintext = plaintext[:i + 1] + 'X' + plaintext[i + 1:]
#         i += 2
#     if len(plaintext) % 2 != 0:
#         plaintext += 'X'
#     return plaintext

# def find_position(matrix, char):
#     # Find the position (row, col) of a character in the matrix
#     for i in range(5):
#         for j in range(5):
#             if matrix[i][j] == char:
#                 return i, j
#     # If the character is not found, return a default position (e.g., (0, 0))
#     return -1, -1  # You can choose a different default position if needed

            
# def encrypt(plaintext, key):
#     matrix= create_matrix(key)
#     plaintext= prep_input(plaintext)
#     ciphertext=''

#     for i in (0, len(plaintext),2):
#         char1=plaintext[i]
#         char2=plaintext[i+1]

#         row1, col1=find_position(matrix, char1)
#         row2, col2=find_position(matrix, char2)

#         if row1==row2:
#             ciphertext += matrix[row1][(col1 + 1) % 5]
#             ciphertext += matrix[row2][(col2 + 1) % 5]
#         elif col1 == col2:
#             ciphertext += matrix[(row1 + 1) % 5][col1]
#             ciphertext += matrix[(row2 + 1) % 5][col2]
#         else:
#             ciphertext += matrix[row1][col2]
#             ciphertext += matrix[row2][col1]

#     return ciphertext

# def decrypt(ciphertext,key):
#     matrix= create_matrix(key) 
#     plaintext=''

#     for i in range(0, len(ciphertext), 2):
#         char1 = ciphertext[i]
#         char2 = ciphertext[i + 1]
        
#         row1, col1 = find_position(matrix, char1)
#         row2, col2 = find_position(matrix, char2)
        
#         if row1 == row2:
#             plaintext += matrix[row1][(col1 - 1) % 5]
#             plaintext += matrix[row2][(col2 - 1) % 5]
#         elif col1 == col2:
#             plaintext += matrix[(row1 - 1) % 5][col1]
#             plaintext += matrix[(row2 - 1) % 5][col2]
#         else:
#             plaintext += matrix[row1][col2]
#             plaintext += matrix[row2][col1]

#     return plaintext

# key='shreeshail'
# plaintext= 'Life of prime minister in danger'
# encrypted_text= encrypt(plaintext, key)
# decrypted_text= decrypt(plaintext, key)

# print("Original text:", plaintext)
# print("Encrypted text:", encrypted_text)
# print("Decrypted text:", decrypted_text)

    

def create_playfair_matrix(key):
    # Create a 5x5 matrix (key table) from the given key
    matrix = [['' for _ in range(5)] for _ in range(5)]
    key = key.replace(" ", "").upper()  # Remove spaces and convert to uppercase
    key += 'ABCDEFGHIKLMNOPQRSTUVWXYZ'  # Append the remaining alphabet without 'J'

    k = 0
    for i in range(5):
        for j in range(5):
            matrix[i][j] = key[k]
            k += 1

    return matrix

def prepare_input(text):
    # Prepare the input text by removing spaces and converting to uppercase
    text = text.replace(" ", "").upper()
    # Replace 'J' with 'I' since they share the same position in the key table
    text = text.replace("J", "I")
    # Insert 'X' between repeated letters and add a trailing 'X' if the text length is odd
    i = 0
    while i < len(text) - 1:
        if text[i] == text[i + 1]:
            text = text[:i + 1] + 'X' + text[i + 1:]
        i += 2
    if len(text) % 2 != 0:
        text += 'X'
    return text

def find_position(matrix, char):
    # Find the position (row, col) of a character in the matrix
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == char:
                return i, j
    # If the character is not found, return a default position (e.g., (0, 0))
    return 0, 0  # You can choose a different default position if needed


def encrypt_playfair(plaintext, key):
    matrix = create_playfair_matrix(key)
    plaintext = prepare_input(plaintext)
    ciphertext = ""

    for i in range(0, len(plaintext), 2):
        char1 = plaintext[i]
        char2 = plaintext[i + 1]

        row1, col1 = find_position(matrix, char1)
        row2, col2 = find_position(matrix, char2)

        if row1 == row2:
            ciphertext += matrix[row1][(col1 + 1) % 5]
            ciphertext += matrix[row2][(col2 + 1) % 5]
        elif col1 == col2:
            ciphertext += matrix[(row1 + 1) % 5][col1]
            ciphertext += matrix[(row2 + 1) % 5][col2]
        else:
            ciphertext += matrix[row1][col2]
            ciphertext += matrix[row2][col1]

    return ciphertext

def decrypt_playfair(ciphertext, key):
    matrix = create_playfair_matrix(key)
    plaintext = ""

    for i in range(0, len(ciphertext), 2):
        char1 = ciphertext[i]
        char2 = ciphertext[i + 1]

        row1, col1 = find_position(matrix, char1)
        row2, col2 = find_position(matrix, char2)

        if row1 == row2:
            plaintext += matrix[row1][(col1 - 1) % 5]
            plaintext += matrix[row2][(col2 - 1) % 5]
        elif col1 == col2:
            plaintext += matrix[(row1 - 1) % 5][col1]
            plaintext += matrix[(row2 - 1) % 5][col2]
        else:
            plaintext += matrix[row1][col2]
            plaintext += matrix[row2][col1]

    return plaintext

# Example usage:
# key = "SECRETKEY"
# plaintext = "HELLO WORLD"

plaintext = input("Enter the plaintext: ")
key = (input("Enter the key: "))

encrypted_text = encrypt_playfair(plaintext, key)
decrypted_text = decrypt_playfair(encrypted_text, key)

print("Original text:", plaintext)
print("Encrypted text:", encrypted_text)
print("Decrypted text:", decrypted_text)
