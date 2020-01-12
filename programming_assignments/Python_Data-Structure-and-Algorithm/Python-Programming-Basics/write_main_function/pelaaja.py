# OPEY 2015
# Luokka eraan pelin pelaajan kuvaamiseen.
# Kirjoittanut Ville Piiparinen

class Pelaaja:
    # Metodi __init__ luo uuden pelaajan. nimi (merkkijono) ja
    # opiskelijastatus (totuusarvo) annetaan parametrina. Saldoksi alustetaan 0.

    def __init__(self, nimi, opiskelija):
        self.__pelimerkit = 0
        self.__nimi = nimi
        self.__opiskelija = opiskelija

    # Metodi palauttaa pelimerkkien maaran

    def kerro_saldo(self):
        return self.__pelimerkit

    # Metodi palauttaa pelaajan nimen

    def kerro_nimi(self):
        return self.__nimi

    # Metodi palauttaa tiedon opiskelijastatuksesta

    def onko_opiskelija(self):
        return self.__opiskelija

    # Metodi lisaa pelaajalle pelimerkkeja parametrina annetun maaran
    # Metodi ei tee mitaan jos parametri on negatiivinen.

    def lisaa_pelimerkkeja(self, pelimerkkeja):
        if pelimerkkeja > 0:
            self.__pelimerkit = pelimerkkeja

    # Metodi pelaa pelin ja kayttaa pelaajan pelimerkkeja.
    # Pelin normaalihinta on 4 pelimerkkia. Alennuspeli on puolet tasta
    # tieto onko kyse alennuspelista saadaan metodin parametrina.
    # Kaikki pelit maksavat opiskelijalle vain yhden pelimerkin
    # Pelia ei voi pelata mikali kayttajalle ei ole tarpeeksi pelimerkkeja.
    # Metodi palauttaa True tai False riippuen siita onnistuuko pelaaminen.


    def pelaa_peli(self, alennus):
        if self.__opiskelija:
            maksu = 1
        elif alennus:
            maksu = 2
        else:
            maksu = 4
        if self.__pelimerkit - maksu >= 0:
            self.__pelimerkit -= maksu
            return True
        else:
            return False

    # Metodi palauttaa merkkijonon, joka sisaltaa pelaakan nimen, opiskelijastatuksen
    # ja pelimerkkien lukumaaran

    def __str__(self):
        if self.__opiskelija:
            opiskelijamerkkijono = "opiskelija"
        else:
            opiskelijamerkkijono = "ei opiskelija"
        mjono = "{:s}, {:s}, {:d} pelimerkkia".format(
            self.__nimi, opiskelijamerkkijono, self.__pelimerkit)
        return mjono