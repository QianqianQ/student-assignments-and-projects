import pelaaja

def main():
    Player1_name="Matti Paasikivi"
    Player1_Status="on"
    if Player1_Status=="on":
        Status1=True
    else:
        Status1=False
    Player1=pelaaja.Pelaaja(Player1_name,Status1)
    Player1.lisaa_pelimerkkeja(10)
    print("Ensimmaisen pelaajan saldo on %d pelimerkkia."%(Player1.kerro_saldo()))
    name=input("Anna uuden pelaajan nimi.\n")
    Player2_Status=input("Opiskelija (on/ei) ?.\n")
    if Player2_Status=="on":
        Status2=True
    else:
        Status2=False
    Player2=pelaaja.Pelaaja(name,Status2)
    chip_amount=int(input("Montako pelimerkkia toiselle pelaajalle lisataan?.\n"))
    Player2.lisaa_pelimerkkeja(chip_amount)
    game=int(input("Pelataanko toisella pelaajalla normaali(1)- vai alennuspeli(2).\n"))
    If_successful_2=Player2.pelaa_peli(game)

    if If_successful_2==True:
      print("Peli onnistui!")
    else:
        print("Pelaaminen ei onnistunut.")

    If_successful_1=Player1.pelaa_peli(1)
    print("Ensimmaisen pelaajan saldo on %d pelimerkkia."%Player1.kerro_saldo())
    If_successful_1_2=Player1.pelaa_peli(2)
    print(Player1)
    print(Player2)


main()