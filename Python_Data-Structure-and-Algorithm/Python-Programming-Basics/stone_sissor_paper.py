import random
# Maaritellaan vakioita, joiden avulla on helppo kasitella tietokoneen
# ja kayttajan valintoja seka pelin voittajaa.
KIVI = 1
SAKSET = 2
PAPERI = 3
VALINNAT = ["tyhja", "kivi", "sakset", "paperi"]
VALINTA_LKM = 3
TIETOKONE = -1
PELAAJA = 1
TASAPELI = 0


# Funktio alustaa tietokoneen arpomisessa kayttaman
# satunnaislukugeneraattorin kayttajan antamalla luvulla.
def alusta():
    print("Tervetuloa pelaamaan kivi-sakset-paperi-pelia.")
    rivi = input("Anna siemenluku tietokoneen arpomista varten.\n")
    siemenluku = int(rivi)
    random.seed(siemenluku)


# Funktio arpoo ja palauttaa tietokoneen valinnan (kivi, sakset tai
# paperi) satunnaislukugeneraattorin avulla.

def tietokoneen_valinta():
    return random.randint(1, VALINTA_LKM)

    # Jatka ohjelman kirjoittamista tahan.
def kayttajan_valinta():
    print("Valitse joku seuraavista:\n1 = KIVI, 2 = SAKSET, 3 = PAPERI")
    select=(int(input("Anna valintasi.\n")))
    while (select!=1) and (select!=2) and (select!=3):
        select=(int(input("Anna valintasi.\n")))
        continue
    return select

def kerro_voittaja(pelaajan_valinta, koneen_valinta):
    while pelaajan_valinta==KIVI:
        if koneen_valinta==SAKSET:
            return PELAAJA
        elif koneen_valinta==PAPERI:
            return TIETOKONE
        else:
            return TASAPELI
    while pelaajan_valinta==SAKSET:
        if koneen_valinta==PAPERI:
            return PELAAJA
        elif koneen_valinta==KIVI:
            return TIETOKONE
        else:
            return TASAPELI
    while pelaajan_valinta==PAPERI:
        if koneen_valinta==KIVI:
            return PELAAJA
        elif koneen_valinta==SAKSET:
            return TIETOKONE
        else:
            return TASAPELI

def main():
    alusta()
    computer=tietokoneen_valinta()
    user=kayttajan_valinta()
    result=kerro_voittaja(user,computer)
    while result==TASAPELI:
        print("Tietokoneen valinta oli",VALINNAT[computer])
        print("Sinun valintasi oli",VALINNAT[user])
        print("Peli ei viela ratkennut, yrita uudelleen.")
        computer = tietokoneen_valinta()
        user = kayttajan_valinta()
        result = kerro_voittaja(user, computer)
        if result==TASAPELI:
            continue
        else:
            break
    if result==PELAAJA:
        print("Tietokoneen valinta oli",VALINNAT[computer])
        print("Sinun valintasi oli",VALINNAT[user])
        print("Sina voitit!")
    else:
        print("Tietokoneen valinta oli", VALINNAT[computer])
        print("Sinun valintasi oli", VALINNAT[user])
        print("Tietokone voitti!")



main()












