import os
def main():
    f=input("Mista tiedostosta sanat luetaan?\n")

    if os.path.isfile(f)==True:
        myfile = open(f, "r")
        print("Tiedosto %s sisaltaa seuraavat sanat:" % f)
        changdu = 0
        amount=0
        for item in myfile:
            item=item.rstrip()
            fenjie=item.split(" ")
            for i in fenjie:
                print(i)
                changdu+=len(i)
                amount+=1
        print("---------------------------------------")
        print("Tiedostossa oli yhteensa %d sanaa ja %d kirjainta."%(amount,changdu))
        myfile.close()
    else:
        print("Virhe tiedoston %s lukemisessa. Ohjelman suoritus paattyy."%f)


main()