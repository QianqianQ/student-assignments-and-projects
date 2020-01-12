def pyyda_kupit():
    print("juomasi kahvikuppien maara.")
    cups=[]
    week_day=7
    for i in range(week_day):
        a=int(input(""))
        cups.append(a)
    return cups

def tulosta_kustannukset(kahvikupit, kupin_tilavuus, kilohinta):
    cost=[]
    week_day=7
    total_cost=0
    for i in range(week_day):
        c=((kahvikupit[i]*kupin_tilavuus)/10)*0.06*kilohinta
        total_cost=total_cost+c
        cost.append(c)
    print("Kupit   Hinta (eur)")
    for i in range(week_day):
        print("%3d       %.2f"%(kahvikupit[i],cost[i]))
    print("------------------------------")
    print("Kulut yhteensa %3.2f euroa."%total_cost)

def main():
    print("Ohjelma analysoi viikoittaista kahvinkulutusta.")
    size=float(input("Anna kahvikupin koko (dl).\n"))
    price=float(input("Anna kahvin kilohinta (eur).\n"))
    print("Anna viikon jokaisena paivana")
    cups=pyyda_kupit()
    tulosta_kustannukset(cups,size,price)

main()

