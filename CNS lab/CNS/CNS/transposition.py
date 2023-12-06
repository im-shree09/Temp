import math

def encryption(plain_text, key):
    len_key = len(key)
    len_plain = len(plain_text)
    row = int(math.ceil(len_plain / len_key))
    matrix = [ ['X']*len_key for i in range(row) ]
    t = 0
    for r in range(row):
        for c,ch in enumerate(plain_text[t : t+ len_key]):
            matrix[r][c] = ch
        t += len_key

    # print(matrix)
    sort_order = sorted([(ch,i) for i,ch in enumerate(key)])  #to make alphabetically order of chars
    # print(sort_order)

    cipher_text = ''
    for ch,c in sort_order:
        for r in range(row):
            cipher_text += matrix[r][c]
    
    return cipher_text

def decryption(cipher_text, key) :

    len_plain = len(cipher_text)
    len_key = len(key)
    row = int(math.ceil(len_plain / len_key))

    matrix_new = [ ['X']*len_key for i in range(row) ]
    key_order = [ key.index(ch) for ch in sorted(list(key))]  #to make original key order when we know keyword
    # print(key_order)

    t = 0
    for c in key_order:
        for r,ch in enumerate(cipher_text[t : t+ row]):
            matrix_new[r][c] = ch
    t += row
    # print(matrix_new) 

    p_text = ''
    for r in range(row):
        for c in range(len_key):
            p_text += matrix_new[r][c] if matrix_new[r][c] != 'X' else ''

    return plain_text

plain_text = input("Enter data: ")
key = input("Enter key: ")

cipher = encryption(plain_text, key)
print(cipher)

plain_text = decryption(cipher, key)
print(plain_text)