def caesar_encrypt(data, key) :
    encryted_str = ""
    for i in data:
        if ord(i) >= ord('a') and ord(i) <= ord('z') :
            encryted_str += chr(((ord(i)-ord('a')+key))%26 + ord('a'))
        elif ord(i) >= ord('A') and ord(i) <= ord('Z'):
            encryted_str += chr(((ord(i)-ord('A')+key))%26 + ord('A'))
        else:
            encryted_str += i

    return encryted_str

def caesar_decrypt(data, encrypt) :
    encryted_str = ""
    c = 0

    for j in range(len(data)) :
        if ord(data[j]) >= ord('a') and ord(data[j]) <= ord('z') :
            c = j
            break
        if ord(data[j]) >= ord('A') and ord(data[j]) <= ord('Z') :
            c = j
            break

    for key in range(26):
        if chr(ord(data[c])+key) == encrypt[c] :
            return key    

    return None

data = input("Enter data: ")
key = int(input("Enter key: "))
encrypt = caesar_encrypt(data, key)
decrypt_key = caesar_decrypt(data,encrypt)

print("Encrypted Data: ",encrypt)
print("Decryption Key: ",decrypt_key)
