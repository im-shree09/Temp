import re

def encrypt(s, k):

    railMatrix=[[" " for i in range(len(s))] for j in range(k)]

    flag=0
    row=0

    for i in range(len(s)):
        railMatrix[row][i]=s[i]

        if row==0:
            flag=0
        elif row==k-1:
            flag=1
        if flag==0:
            row+=1
        else:
            row-=1

    ct=[]
    for i in range(k):
        for j in range(len(s)):
            if railMatrix[i][j]!=' ':
                ct.append(railMatrix[i][j])

    cipher="".join(ct)
    print("Cipher Text: ",cipher)
    return cipher

def cipher_decryption(s, k):

    railMatrix=[[" " for i in range(len(s))] for j in range(k)]
    row = 0
    flag = 0

    for i in range(len(s)):
        railMatrix[row][i]=s[i]

        if row==0:
            flag=0
        elif row==k-1:
            flag=1
        if flag==0:
            row+=1
        else:
            row-=1


    ordr = 0
    for i in range(k):
        for j in range(len(s)):
            temp = railMatrix[i][j]
            if re.search(" ", temp):
                continue
            else:
                railMatrix[i][j] = s[ordr]
                ordr += 1



    flag = 0
    row = 0
    decryp_text = ""
    for i in range(len(s)):
        if flag == 0:
            decryp_text += railMatrix[row][i]
            row += 1
            if row == k:
                flag = 1
                row -= 1
            # inner if
        elif flag == 1:
            row -= 1
            decryp_text += railMatrix[row][i]
            if row == 0:
                flag = 0
                row = 1
            # inner if
        # if-else
    # for

    decryp_text = re.sub(" ", "", decryp_text)
    return decryp_text

data = input("Enter data: ")
key = int(input("Enter key: "))

cipher = encrypt(data, key)

plain = cipher_decryption(cipher, key)

print(plain)