import os
def find_max(amount):
    for i in range(len(amount)):
        amount[i]=amount[i]*(i+1)
    a=max(amount)
    return a

def main():
    name = []
    amount = []
    print("Ohjelma analysoi albumin parhaan kappaleen.")
    f=input("Anna kuuntelutiedot sisaltavan tiedoston nimi.\n")
    if os.path.isfile(f)==False:
        print("Tiedoston %s lukeminen ei onnistu.\nOhjelma paattyy."%f)
    else:

        myfile=open(f,"r")
        for i in myfile:
            k,v=i.strip().split('/')
            v1=int(v)
            name.append(k)
            amount.append(v1)
        max_num=find_max(amount)
        amount.index(max_num)
        print("Suosituin kappale oli:",name[amount.index(max_num)])


main()
