def encrypt(text, shift):
    encrypted_text = ""
    for char in text:
        if char.isalpha():
            if char.islower():
                encrypted_text += chr((ord(char) - ord('a' ) + shift) % 26 + ord('a'))
            elif char.isupper():
                encrypted_text += chr((ord(char) - ord('A' ) + shift) % 26 + ord('A'))
        else:
            encrypted_text += char
    return encrypted_text

def decrypt(encrypted_text, shift):
    decrypted_text = ""
    for char in encrypted_text:
        if char.isalpha():
            if char.islower():
                decrypted_text += chr((ord(char) - ord('a' ) - shift) % 26 + ord('a'))
            elif char.isupper():
                decrypted_text += chr((ord(char) - ord('A' ) - shift) % 26 + ord('A'))
        else:
            decrypted_text += char
    return decrypted_text

text = input("Enter the text: ")
shift = int(input("Enter the shift value: "))

encrypted_text = encrypt(text, shift)
print("Encrypted text:", encrypted_text)

decrypted_text = decrypt(encrypted_text, shift)
print("Decrypted text:", decrypted_text)
