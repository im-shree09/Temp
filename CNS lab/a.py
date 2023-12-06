def prepare_key(key):
    prepared_key = ""
    used = [False] * 26  # to keep track of used letters

    # Remove spaces from the key and convert to uppercase
    for c in key:
        if c.isalpha():
            c = c.upper()
            if not used[ord(c) - ord('A')]:
                prepared_key += c
                used[ord(c) - ord('A')] = True

    # Fill the remaining spaces with the alphabet (except 'J' which is combined with 'I')
    for c in range(ord('A'), ord('Z') + 1):
        if chr(c) != 'J' and not used[c - ord('A')]:
            prepared_key += chr(c)
            used[c - ord('A')] = True

    return prepared_key

def create_matrix(key):
    prepared_key = prepare_key(key)
    matrix = [['' for _ in range(5)] for _ in range(5)]
    k = 0

    for i in range(5):
        for j in range(5):
            matrix[i][j] = prepared_key[k]
            k += 1

    return matrix

def find_position(matrix, char):
    if char == 'J':
        char = 'I'  # treat 'J' as 'I'

    for i in range(5):
        for j in range(5):
            if matrix[i][j] == char:
                return i, j

def encrypt_playfair(plaintext, key):
    matrix = create_matrix(key)
    ciphertext = ""
    length = len(plaintext)

    for i in range(0, length, 2):
        a = plaintext[i]
        b = plaintext[i + 1] if i + 1 < length else 'X'  # If the text length is odd, add 'X' at the end

        row_a, col_a = find_position(matrix, a)
        row_b, col_b = find_position(matrix, b)

        # Case 1: In the same row
        if row_a == row_b:
            ciphertext += matrix[row_a][(col_a + 1) % 5]
            ciphertext += matrix[row_b][(col_b + 1) % 5]
        # Case 2: In the same column
        elif col_a == col_b:
            ciphertext += matrix[(row_a + 1) % 5][col_a]
            ciphertext += matrix[(row_b + 1) % 5][col_b]
        # Case 3: Forming a rectangle
        else:
            ciphertext += matrix[row_a][col_b]
            ciphertext += matrix[row_b][col_a]

    return ciphertext

def decrypt_playfair(ciphertext, key):
    matrix = create_matrix(key)
    plaintext = ""
    length = len(ciphertext)

    for i in range(0, length, 2):
        a = ciphertext[i]
        b = ciphertext[i + 1] if i + 1 < length else 'X'  # If the text length is odd, add 'X' at the end

        row_a, col_a = find_position(matrix, a)
        row_b, col_b = find_position(matrix, b)

        # Case 1: In the same row
        if row_a == row_b:
            plaintext += matrix[row_a][(col_a - 1) % 5]  # Decrement by 1
            plaintext += matrix[row_b][(col_b - 1) % 5]  # Decrement by 1
        # Case 2: In the same column
        elif col_a == col_b:
            plaintext += matrix[(row_a - 1) % 5][col_a]  # Decrement by 1
            plaintext += matrix[(row_b - 1) % 5][col_b]  # Decrement by 1
        # Case 3: Forming a rectangle
        else:
            plaintext += matrix[row_a][col_b]
            plaintext += matrix[row_b][col_a]

    return plaintext

# Example usage:
key = input("Enter the key: ")
plaintext = input("Enter the plaintext: ")

# Remove spaces and convert to uppercase
plaintext = ''.join(plaintext.split())
plaintext = plaintext.upper()

ciphertext = encrypt_playfair(plaintext, key)
print("Encrypted text:", ciphertext)

decrypted_text = decrypt_playfair(ciphertext, key)
print("Decrypted text:", decrypted_text)


# def create_matrix(key):
#     matrix = []
#     key = key.replace(' ', '').upper()
#     key += 'ABCDEFGHIKLMNOPQRSTUVWXYZ'
#     for char in key:
#         if char not in matrix:
#             matrix.append(char)
#     return matrix

# def prep_input(plaintext):
#     plaintext = plaintext.replace(' ', '').upper()
#     plaintext = plaintext.replace('J', 'I')

#     i = 0
#     while i < len(plaintext) - 1:
#         if plaintext[i] == plaintext[i + 1]:
#             plaintext = plaintext[:i + 1] + 'X' + plaintext[i + 1:]
#         i += 2
#     if len(plaintext) % 2 != 0:
#         plaintext += 'X'
#     return plaintext

# def find_position(matrix, char):
#     for i in range(5):
#         for j in range(5):
#             if matrix[i][j] == char:
#                 return i, j
#     return -1, -1

# def encrypt(plaintext, key):
#     matrix = create_matrix(key)
#     plaintext = prep_input(plaintext)
#     ciphertext = ''

#     for i in range(0, len(plaintext), 2):
#         char1 = plaintext[i]
#         char2 = plaintext[i + 1]

#         row1, col1 = find_position(matrix, char1)
#         row2, col2 = find_position(matrix, char2)

#         if row1 == row2:
#             ciphertext += matrix[row1][(col1 + 1) % 5]
#             ciphertext += matrix[row2][(col2 + 1) % 5]
#         elif col1 == col2:
#             ciphertext += matrix[(row1 + 1) % 5][col1]
#             ciphertext += matrix[(row2 + 1) % 5][col2]
#         else:
#             ciphertext += matrix[row1][col2]
#             ciphertext += matrix[row2][col1]

#     return ciphertext

# def decrypt(ciphertext, key):
#     matrix = create_matrix(key)
#     plaintext = ''

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

# key = 'shreeshail'
# plaintext = 'Life of prime minister in danger'
# encrypted_text = encrypt(plaintext, key)
# decrypted_text = decrypt(encrypted_text, key)

# print("Original text:", plaintext)
# print("Encrypted text:", encrypted_text)
# print("Decrypted text:", decrypted_text)
