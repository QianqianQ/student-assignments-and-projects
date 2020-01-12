start = int(input("Anna aloitusvuosi.\n"))
endyear = int(input("Anna lopetusvuosi.\n"))
print("Karkausvuodet em. valilta:")
year=start
while year<=endyear:
    if ((year%4 == 0)and (year%100!=0) )or (year%400==0):
        print(year)
        year+=1
    else:
        year+=1
