# def decrypt_brute_force(encrypted_text):
#     decrypted_results = []

#     for shift in range(26):
#         decrypted_text = ""
#         for char in encrypted_text:
#             if char.isalpha():
#                 if char.islower():
#                     decrypted_text += chr((ord(char) - ord('a' ) - shift) % 26 + ord('a'))
#                 elif char.isupper():
#                     decrypted_text += chr((ord(char) - ord('A' ) - shift) % 26 + ord('A'))
#             else:
#                 decrypted_text += char

#         decrypted_results.append(decrypted_text)

#     return decrypted_results

# # Input encrypted text
# encrypted_text = input("Enter the encrypted text: ")

# # Attempt to decrypt using all possible shifts
# decrypted_results = decrypt_brute_force(encrypted_text)

# # Display possible decrypted texts for user to choose from
# print("Possible decrypted texts:")
# for i, decrypted_text in enumerate(decrypted_results):
#     print(f"{i + 1}. {decrypted_text}")


# Sample dictionary of valid words
# valid_words = ["hello", "world","shree", "python", "programming", "example", "shift", "cipher", "encryption", "decryption"]

# def is_valid_word(word):
#     return word.lower() in valid_words

# def decrypt_with_meaning(encrypted_text):
#     best_decrypted_text = ""
#     best_word_count = 0

#     for shift in range(26):
#         decrypted_text = ""
#         for char in encrypted_text:
#             if char.isalpha():
#                 if char.islower():
#                     decrypted_text += chr((ord(char) - ord('a') - shift) % 26 + ord('a'))
#                 elif char.isupper():
#                     decrypted_text += chr((ord(char) - ord('A') - shift) % 26 + ord('A'))
#             else:
#                 decrypted_text += char

#         decrypted_words = decrypted_text.split()
#         valid_word_count = sum(1 for word in decrypted_words if is_valid_word(word))

#         if valid_word_count > best_word_count:
#             best_word_count = valid_word_count
#             best_decrypted_text = decrypted_text

#     return best_decrypted_text

# # Input encrypted text
# encrypted_text = input("Enter the encrypted text: ")

# # Decrypt and find the most meaningful result
# meaningful_decrypted_text = decrypt_with_meaning(encrypted_text)
# print("Meaningful decrypted text:", meaningful_decrypted_text)


import nltk
from nltk.corpus import words as nltk_words

# nltk.download("words")

def is_valid_word(word):
    return word.lower() in nltk_words.words()

def decrypt_with_meaning(encrypted_text):
    best_decrypted_text = ""
    best_word_count = 0

    for shift in range(26):
        decrypted_text = ""
        for char in encrypted_text:
            if char.isalpha():
                if char.islower():
                    decrypted_text += chr((ord(char) - ord('a') - shift) % 26 + ord('a'))
                elif char.isupper():
                    decrypted_text += chr((ord(char) - ord('A') - shift) % 26 + ord('A'))
            else:
                decrypted_text += char

        decrypted_words = decrypted_text.split()
        valid_word_count = sum(1 for word in decrypted_words if is_valid_word(word))

        if valid_word_count > best_word_count:
            best_word_count = valid_word_count
            best_decrypted_text = decrypted_text

    return best_decrypted_text

encrypted_text = input("Enter the encrypted text: ")
meaningful_decrypted_text = decrypt_with_meaning(encrypted_text)
print("Meaningful decrypted text:", meaningful_decrypted_text)
