import random


def main():
    syote = input("Valitse aloitusluku ohjelman arvontaa varten\n")
    aloitus = int(syote)
    random.seed(aloitus)
    voitot = 0
    kerrat = int(input("Montako kertaa koetta toistetaan?\n"))
    for i in range(kerrat):
        oikea_ovi = random.randint(1, 3)
        choose=int(input("Yhden oven takana on auto. Arvaa ovi (1-3)?\n"))
        if choose!=1 and oikea_ovi!=1:
            print("Juontaja avasi oven 1")
            choose2=int(input("Haluatko vaihtaa arvaustasi (1-3, 0 == ei)?\n"))
            if choose2==0:
                choose2=choose
                if choose2==oikea_ovi:
                    print("Voitit auton!")
                    voitot+=1
                    continue
                else:
                    print("Ei voittoa.")
                    continue
            else:
                if choose2==oikea_ovi:
                    print("Voitit auton!")
                    voitot+=1
                    continue
                else:
                    print("Ei voittoa.")
                    continue
        elif (choose==1 or oikea_ovi==1) and (choose!=2 and oikea_ovi!=2):
            print("Juontaja avasi oven 2")
            choose2 = int(input("Haluatko vaihtaa arvaustasi (1-3, 0 == ei)?\n"))
            if choose2 == 0:
                choose2 = choose
                if choose2 == oikea_ovi:
                    print("Voitit auton!")
                    voitot+=1
                    continue
                else:
                    print("Ei voittoa.")
                    continue
            else:
                if choose2 == oikea_ovi:
                    print("Voitit auton!")
                    voitot+=1
                    continue
                else:
                    print("Ei voittoa.")
                    continue
        else:
            print("Juontaja avasi oven 3")
            choose2 = int(input("Haluatko vaihtaa arvaustasi (1-3, 0 == ei)?\n"))
            if choose2 == 0:
                choose2 = choose
                if choose2 == oikea_ovi:
                    print("Voitit auton!")
                    voitot+=1
                    continue
                else:
                    print("Ei voittoa.")
                    continue
            else:
                if choose2 == oikea_ovi:
                    print("Voitit auton!")
                    voitot+=1
                    continue
                else:
                    print("Ei voittoa.")
                    continue
    rate=voitot/kerrat
    print("Voittotodennakoisyytesi oli",rate)

main()