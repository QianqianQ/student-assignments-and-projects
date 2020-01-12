# OPEY1 2015
# Testiohjelma tehtavaan 9.4
# Kirjoittanut vanhan Java-kurssin assistenttien koodin ideoiden
# pohjalta Kerttu Pollari-Malmi
#
# Ohjelma luo Alkuelain-olioita ja testaa niille luokan metodeita.
import alkuelain


# Funktio lukee kayttajalta rivin, jossa on pilkuilla toisistaan erotettuja
# kokonaislukuja. Se tekee ja palauttaa listan, jossa on samat kokonaisluvut.
# Jos rivilla jokin osa ei ole kokonaisluku, funktio sijoittaa listaan
# talle paikalle pienimman mahdollisen geenin arvon.

def lue_geenit():
    rivi = input()
    lista = rivi.split(",")
    annetut_geenit = []
    for alkio in lista:
        try:
            annetut_geenit.append(int(alkio))
        except ValueError:
            annetut_geenit.append(alkuelain.Alkuelain.PIENIN_GEENI)
    return annetut_geenit


def main():
    print("Alkumeressa tapahtuu ...")
    print("Aluksi oli kaksi alkuelainta, Aatami ja Eeva.")
    print("Anna Aatamin geenit yhdella rivilla, erota toisistaan pilkulla.")
    geenitiedot = lue_geenit()
    aatami = alkuelain.Alkuelain("Aatami", geenitiedot)
    print("Anna Eevan geenit yhdella rivilla, erota toisistaan pilkulla.")
    geenitiedot = lue_geenit()
    eeva = alkuelain.Alkuelain("Eeva", geenitiedot)
    print()
    print('Aatami sanoi: "Olet kaunis."')
    dolly1 = aatami.pariudu(eeva, "Dolly1")
    print("Nyt alkuelaimia oli jo kolme:")
    print(aatami)
    print(eeva)
    print(dolly1)
    print()
    print("Dolly tunsi kuitenkin olonsa yksinaisesti, joten han jakautui.")
    dolly2 = dolly1.klooni("Dolly2")
    print("Kukaan ei meinannut erottaa kahta Dollya toisistaan.")
    print(dolly1)
    print(dolly2)
    print()
    print("Eraana paivana toiselle Dollylle kavi hassusti:")
    # Tassa yritetaan tarkoituksella muuttaa myos olemattomia geeneja ja
    # antaa joillekin geeneille vaaria arvoja. Jos ohjelmasi ei selvia
    # siita oikein, mutaatio-metodissasi on virhe.
    for i in range(-4, alkuelain.Alkuelain.GEENIEN_MAARA + 2, 2):
        dolly2.mutaatio(i, i - 1)
    print(dolly2)
    print("Ensimmainen Dolly oli kuitenkin sailyttanyt alkuperaiset geeninsa.")
    print(dolly1)
    # Jos ensimmainenkin Dolly oli muuttunut, sinulla on virhe __init__-
    # tai klooni-metodissa.
    print()
    print("Ensimmainen Dolly kohtasi ulkoavaruudesta saapuneen muukalaisen.")
    print("Anna muukalaisen geenit.")
    geenitiedot = lue_geenit()
    vieras = alkuelain.Alkuelain("Gregory", geenitiedot)
    print("Ja niihan siina kavi, etta kohtaamisella oli pian seurauksia.")
    juniori = dolly1.pariudu(vieras, "DollyJr")
    print(juniori)
    print()
    print("Ja he kaikki elivat elamansa onnellisina loppuun asti.")
    print(aatami)
    print(eeva)
    print(dolly1)
    print(vieras)
    print(juniori)
    print(dolly2)


main()