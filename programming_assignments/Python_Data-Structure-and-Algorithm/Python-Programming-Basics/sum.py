print("Aloita syottamalla lukuja. Lopeta negatiivisella.")
sumnum=0
a=0
while sumnum>=0:
        sumnum=int(input())
        if sumnum<0:
            break
        a=a+sumnum
print("Lukujen summa on",a)
    