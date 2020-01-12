def laske_voima(massa, alkunopeus):
    a=(alkunopeus-5)/3
    F=massa*a
    return F

def laske_vastaava_massa(voima):
    m=voima/9.81
    return m

def main():
    print("Anna laskuvarjohyppaajan putoamisnopeus. Tyypillinen nopeus\nmahallaan putoamiselle on noin 54 m/s ja pystysuoraan 90 m/s.")
    s1=int(input())
    m=float(input("Anna hyppaajan massa (kg).\n"))
    F=laske_voima(m,s1)
    m2=laske_vastaava_massa(F)
    print("Laskuvarjon avaus aiheuttaa hyppaajalle","%.0f"%F,"Newtonin voiman.")
    print("Voima vastaa","%.0f"%m2,"kilogramman massaa.")

main()
