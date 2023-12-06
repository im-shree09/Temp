def main():
    choice = int(input("Choose an option:\n1. Encryption\n2. Decryption\nEnter your choice (1 or 2): "))
    input()  

    if choice == 1:
        # Encryption
        plain_text = input("\nEnter plain text: ")
        key = input("\nEnter key: ")

        plain_text = plain_text.replace(" ", "").lower()
        key = key.replace(" ", "").lower()

        # Encryption
        cipher_text = ""
        for i in range(len(plain_text)):
            val = (ord(plain_text[i]) - ord('a') + ord(key[i % len(key)]) - ord('a')) % 26
            cipher_text += chr(ord('a') + val)

        print("\nCipher Text:", cipher_text)

    elif choice == 2:
        # Decryption
        cipher_text = input("\nEnter cipher text: ")
        key = input("\nEnter key: ")

        key = key.replace(" ", "").lower()

        # Decryption
        decrypted = ""
        for i in range(len(cipher_text)):
            val = (ord(cipher_text[i]) - ord('a') - (ord(key[i % len(key)]) - ord('a')) + 26) % 26
            decrypted += chr(ord('a') + val)

        print("\nAfter decryption:", decrypted)

    else:
        print("Invalid choice. Please choose 1 or 2.")

if __name__ == "__main__":
    main()
