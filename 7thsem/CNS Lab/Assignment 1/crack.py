import enchant
from numpy.core.defchararray import lower

dic = enchant.Dict("en-US")

#function to decrypt
def decrypt(text, shift):
    cipher = ""
    text = lower(text)
    text = str(text)
    for c in text:
        # if c == 32:
        #     continue
        t = (ord(c) - shift - 65) % 26
        if t<0:
            t = 26 + t
        cipher += chr(t % 26 + 65)
    #print(cipher)
    return cipher

#main body

cipheredText =  input("Enter secret message: ")

shift = 26

for i in range(shift):
    plainText = decrypt(cipheredText,i)
    if dic.check(plainText):
         print(plainText)
         exit()
print("Cannot Crack the code")