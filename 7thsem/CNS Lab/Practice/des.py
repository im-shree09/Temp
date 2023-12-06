from Crypto.Cipher import DES
from Crypto import Random

iv = Random.get_random_bytes(8)
desEnc = DES.new('01234567'.encode("utf8"), DES.MODE_CFB,iv)
desDec = DES.new('01234567'.encode("utf8"), DES.MODE_CFB,iv)

text = "piyush".encode('utf8')
cipherText = desEnc.encrypt(text)

print('The Encrypted message is \n',cipherText)

print('\n The original plaintext was \n',desDec.decrypt(cipherText))