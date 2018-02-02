def laske_kulutus(matka, bensamaara):
    ave=bensamaara/(matka/100)
    return ave

def vuosikustannus(vuosikilometrit, keskikulutus, litrahinta):
    cost=(vuosikilometrit/100)*keskikulutus*litrahinta
    return cost

def main():
    print("Ohjelma laskee autojen vuosittaisia bensiinikuluja.")
    num_of_car=int(input("Monenko auton tiedot annat?\n"))
    while num_of_car<=0:
        num_of_car = int(input("Monenko auton tiedot annat?\n"))
        continue
    annual_dis=float(input("Mika on autojen vuodessa kulkema matka (km)?\n"))
    price = float(input("Anna bensiinin hinta (eur / l).\n"))
    car=[]
    for i in range(num_of_car):
        print("Anna {}. auton tiedot".format(i+1))
        travel = float(input("Kuljettu matka (km):\n"))
        while travel<=0:
            print("Anna matka uudelleen!")
            travel = float(input())
            continue
        petrol=float(input("Kulutettu bensiini (l):\n"))
        ave=laske_kulutus(travel,petrol)
        consumed=vuosikustannus(annual_dis,ave,price)
        car.append(consumed)
    print("Autojen bensiinikulut vuodessa")
    print("Auto  vuosikulut (eur)")
    for i in range(num_of_car):
        # print("{3d}.{8.2f}".format())
        print("%3d. %8.2f"%(i+1,car[i]))

main()












