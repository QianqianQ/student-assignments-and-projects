import os
import string
def main():
    #dic=dict.fromkeys(string.ascii_lowercase,0)
    f=input("Anna salakirjoitustiedoston nimi?\n")
    if os.path.isfile(f)==False:
        print("Annettua tiedostoa ei ole\ntai sita ei pystyta lukemaan.")
    else:
        string2=[]
        myfile=open(f,"r")
        string=myfile.read()
        dic=get_f(string)
        a=max(dic.items(),key=lambda x:x[1])[0]
        shift=ord(a)-ord('e')
        for i in range(len(string)):
            if string[i].isalpha()==False:
                string2.append(string[i])
            else:
                if ord(string[i])-shift>96:
                    string2.append(chr(ord(string[i])-shift))
                else:
                    string2.append(chr(ord(string[i])+(26-shift)))
        print("Salakirjoitus purettuna:")
        print(''.join(string2),end='')









def get_f(strings):
    letters=[]
    dic={}
    for letter in strings:
        if letter.isalpha()==False:
            continue
        else:
            if letter not in dic:
                dic[letter]=1
            else:
                dic[letter]+=1
    return dic

main()