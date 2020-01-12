figure=[]
a=0
i=0
amount =int(input("Montako lukua annetaan?\n"))
print("Anna luvut omilla riveillaan.")
for i in range(amount):
    b= float(input())
    a += b
    figure.append(b)
ave = a / amount
biggest=int(max(figure))
print("Lukujen keskiarvo on", ave)
print("ja suurin luku on",biggest)