from Crypto.Cipher import AES
from Crypto import Random

key = b'a&HMkjhY&hBGbfgF'
cipher = AES.new(key,AES.MODE_EAX)

data = 'piyush'.encode("utf8")

cipherText = cipher.encrypt(data)

print("Cipher text :", cipherText)

nonce = cipher.nonce
cipher = AES.new(key,AES.MODE_EAX,nonce=nonce)

plainText = cipher.decrypt(cipherText)
print("Plain text: ",plainText)