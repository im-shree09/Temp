import  enchant

Dict = enchant.Dict("en-US")

def deCipher(text,shift):
    cipher = ""
    for c in text:
        t = (ord(c)-65 - shift) % 26
        if t<0:
            t = t + 26
        cipher += chr( t%26 + 65)

    # print(cipher)
    return cipher


cipherText = input("Enter the cipher text \n")

shift = 26

for i in range(26):
    plainText = deCipher(cipherText,i)
    if Dict.check(plainText):
        print(plainText)
        exit()

print("Cannot Crack the code")