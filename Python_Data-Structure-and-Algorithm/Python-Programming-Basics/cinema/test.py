# OPEY1 2017
# Testiohjelma tehtavassa 9.5 kirjoitettavan Elokuvanaytos-luokan
# testaamiseen.
# Kirjoittanut Kerttu Pollari-Malmi

import elokuvanaytos


# Apufunktio kokonaisluvun lukemiseen.

def lue_kokonaisluku():
    kelvollinen_luku = False
    while not kelvollinen_luku:
        try:
            luku = int(input())
            kelvollinen_luku = True
            return luku
        except ValueError:
            print("Ei ollut kokonaisluku. Anna uusi luku!")


# Funktio tulostaa kayttajalle valikon mahdollisista toiminnoista ja
# palauttaa kayttajan valinnan kokonaislukuna.

def valikko():
    print()
    print("Valitse toiminto:")
    print("1. lisaa uusi naytos")
    print("2. tulosta varauskartta")
    print("3. varaa yksi paikka")
    print("4. varaa monta paikkaa")
    print("5. tulosta naytosten tiedot")
    print("6. lopeta")
    vastaus = lue_kokonaisluku()
    return vastaus


# Apufunktio, jonka avuolla kayttaja valitsee haluamansa naytoksen.
# Funktion parametrina on elokuvanaytokset sisaltava lista. Funktio
# palauttaa valitun naytoksen indeksin listassa tai arvon -1, jos
# lista on tyhja tai kayttaja ei valinnut listassa olevaa naytosta.

def valitse_naytos(naytoslista):
    if len(naytoslista) == 0:
        print("Jarjestelmassa ei ole yhtaan elokuvanaytosta.")
        print("Toiminto ei ole mahdollinen.")
        return -1
    else:
        print("Valitse naytoksen numero:")
        i = 0
        while i < len(naytoslista):
            print("{:d}. {:s}".format(i + 1, str(naytoslista[i])))
            i += 1
        naytosnro = lue_kokonaisluku()
        if 1 <= naytosnro <= len(naytoslista):
            return naytosnro - 1
        else:
            print("Vaara naytoksen numero!")
            return -1


# Funktio pyytaa uuden naytoksen tiedot, luo niita vastaavan
# Elokuvanaytos-olion ja lisaa sen parametrina saatuun naytoslistaan.

def lisaa_naytos(naytoslista):
    print("Anna lisattavan naytoksen tiedot.")
    nimi1 = input("Elokuvan nimi:\n")
    aika1 = input("Esitysaika:\n")
    sali1 = input("Esityssali\n")
    print("Rivien lukumaara salissa:")
    rivit1 = lue_kokonaisluku()
    print("Paikkojen lukumaara rivilla:")
    paikat1 = lue_kokonaisluku()
    uusi_naytos = elokuvanaytos.Elokuvanaytos(nimi1, aika1, sali1, \
                                              rivit1, paikat1)
    naytoslista.append(uusi_naytos)


# Funktio tulostaa kayttajan haluaman naytoksen varauskartan.
# Funktio saa parametrina naytokset sisaltavan listan.

def tulosta_varauskartta(naytoslista):
    naytosindeksi = valitse_naytos(naytoslista)
    if naytosindeksi != -1:
        print(naytoslista[naytosindeksi].kerro_varauskartta())


# Funktio varaa halutusta naytoksesta yhden paikan.
# Funktio saa parametrina naytokset sisaltavan listan.

def varaa_yksi_paikka(naytoslista):
    naytosindeksi = valitse_naytos(naytoslista)
    if naytosindeksi != -1:
        print("Anna varattavan paikan rivinumero.")
        rivinro = lue_kokonaisluku()
        print("Anna varattavan paikan numero rivilla.")
        paikkanro = lue_kokonaisluku()
        if naytoslista[naytosindeksi].varaa_paikka(rivinro, paikkanro):
            print("Paikan varaaminen onnistui.")
        else:
            print("Paikan varaaminen ei onnistunut.")


# Funktio varaa halutusta naytoksesta monta vierekkaista paikkaa.
# Funktio saa parametrina naytokset sisaltavan listan.

def varaa_monta_paikkaa(naytoslista):
    naytosindeksi = valitse_naytos(naytoslista)
    if naytosindeksi != -1:
        print("Anna varattavien paikkojen rivinumero.")
        rivinro = lue_kokonaisluku()
        print("Anna ensimmaisen varattavan paikan numero rivilla.")
        paikkanro1 = lue_kokonaisluku()
        print("Anna viimeisen varattavan paikan numero rivilla.")
        paikkanro2 = lue_kokonaisluku()
        if naytoslista[naytosindeksi].varaa_paikat(rivinro, paikkanro1,
                                                   paikkanro2):
            print("Paikkojen varaaminen onnistui.")
        else:
            print("Paikkojen varaaminen ei onnistunut.")


# Funktio tulostaa jarjestelmassa olevien naytosten tiedot.
# Funktio saa parametrina naytokset sisaltavan listan.

def tulosta_naytosten_tiedot(naytoslista):
    if len(naytoslista) == 0:
        print("Jarjestelmassa ei ole yhtaan elokuvanaytosta.")
    else:
        print("Jarjestelmassa olevat naytokset:")
        i = 0
        while i < len(naytoslista):
            print("{:d}. {:s}".format(i + 1, str(naytoslista[i])))
            i += 1


def main():
    elokuvanaytokset = []
    valinta = valikko()
    while valinta != 6:
        if valinta == 1:
            lisaa_naytos(elokuvanaytokset)
        elif valinta == 2:
            tulosta_varauskartta(elokuvanaytokset)
        elif valinta == 3:
            varaa_yksi_paikka(elokuvanaytokset)
        elif valinta == 4:
            varaa_monta_paikkaa(elokuvanaytokset)
        elif valinta == 5:
            tulosta_naytosten_tiedot(elokuvanaytokset)
        valinta = valikko()


main()