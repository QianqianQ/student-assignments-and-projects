# OPEY 2017
# Ohjelma tehtavan 9.3 Matkakortti-luokan testaamiseen.
# Kirjoittanut Ville Piiparinen.

import matkakortti


# Apufunktio desimaaliluvun lukemiseen.

def lue_desimaaliluku():
    kelvollinen_luku = False
    while not kelvollinen_luku:
        try:
            luku = float(input())
            kelvollinen_luku = True
            return luku
        except ValueError:
            print("Ei ollut desimaaliluku. Anna uusi luku!")


# Apufunktio kortin tietojen tulostamiseen. Tata funktiota
# ei tarvita lainkaan, jos tiedot tulostetaan aina kayttamalla
# Matkakortti-luokan __str__-metodin palauttamaa merkkijonoa.
# Tahan on kuitenkin lisatty tama funktio, jotta Goblinin antamat
# pisteet eivat menisi nollille, jos opiskelijan __str__-funktiossa
# on jokin vika.

def tulosta_kortin_tiedot(kortti):
    print("Omistajan nimi:", kortti.kerro_omistaja())
    print("Kortin saldo {:.2f} eur.".format(kortti.kerro_saldo()))
    if kortti.onko_validi():
        print("Kortti on kaytossa.")
    else:
        print("Kortti ei ole kaytossa.")


# Paaohjelma luo kaksi Matkakortti-oliota ja kutsuu niille luokan
# metodeja. Paaohjelma kannattaisi pilkkoa pienemmiksi funktioiksi,
# mutta tassa se on jatetty yhdeksi funktioksi, jotta sen seuraaminen
# olisi aloittelijoille helpompaa.

def main():
    nimi1 = input("Anna 1. kortin omistajan nimi.\n")
    kortti1 = matkakortti.Matkakortti(nimi1)
    print("Luotiin 1. uusi matkakortti:")
    tulosta_kortin_tiedot(kortti1)
    nimi2 = input("Anna 2. kortin omistajan nimi.\n")
    kortti2 = matkakortti.Matkakortti(nimi2)
    print("Luotiin 2. uusi matkakortti:")
    tulosta_kortin_tiedot(kortti2)

    print()
    print("Paljonko 1. kortille ladataan rahaa?")
    summa1 = lue_desimaaliluku()
    kortti1.kasvata_saldoa(summa1)
    print("Kortti 1 saldon kasvatuksen jalkeen:")
    tulosta_kortin_tiedot(kortti1)
    print("Paljonko 1. kortille ladataan uudelleen rahaa?")
    summa1 = lue_desimaaliluku()
    kortti1.kasvata_saldoa(summa1)
    print("Kortin 1 saldo uuden kasvatuksen jalkeen: {:.2f} eur.".format( \
        kortti1.kerro_saldo()))

    print()
    print("Paljonko 2. kortille ladataan rahaa?")
    summa2 = lue_desimaaliluku()
    kortti2.kasvata_saldoa(summa2)
    print("Kortti 2 saldon kasvatuksen jalkeen:")
    tulosta_kortin_tiedot(kortti2)

    print()
    print("Tehdaan matkoja 1. kortilla ...")
    for i in range(3):
        tyyppi = input("Anna matkan tyyppi (sisainen/seutu).\n")
        if tyyppi == "seutu":
            matka_onnistui = kortti1.tee_matka(True)
        else:
            matka_onnistui = kortti1.tee_matka(False)
        if matka_onnistui:
            print("Matka onnistui!")
        else:
            print("Saldo ei riittanyt tai kortti on suljettu.")
    print("Kortti 1 matkojen jalkeen:")
    tulosta_kortin_tiedot(kortti1)

    print()
    print("Tehdaan matkoja 2. kortilla ...")
    for i in range(3):
        tyyppi = input("Anna matkan tyyppi (sisainen/seutu).\n")
        if tyyppi == "seutu":
            matka_onnistui = kortti2.tee_matka(True)
        else:
            matka_onnistui = kortti2.tee_matka(False)
        if matka_onnistui:
            print("Matka onnistui!")
        else:
            print("Saldo ei riittanyt tai kortti on suljettu.")
    print("Kortti 2 matkojen jalkeen:")
    tulosta_kortin_tiedot(kortti2)

    print()
    print("Nollataan 1. kortin saldo:")
    kortti1.nollaa_saldo()
    print("Kortti 1 nollauksen jalkeen:")
    tulosta_kortin_tiedot(kortti1)

    print()
    print("Poistetaan 2. kortti kaytosta:")
    kortti2.poista_kaytosta()
    print("Yritetaan tehda matka 2. kortilla")
    if kortti2.tee_matka(False):
        print("Matkan teko onnisui - ohjelmassasi on jotain pielessa.")
    else:
        print("Matkan teko ei onnistunut - ei olisi pitanytkaan.")

    print()
    print("Tulostetaan molempien korttien tiedot __str__-metodin avulla:")
    print(kortti1)
    print()
    print(kortti2)


main()
