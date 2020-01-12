import sys
def tee_pituusmuunnos():
    feet=float(input("Montako jalkaa (1-9)?\n"))
    inch=float(input("Montako tuumaa (0-11)?\n"))
    if (feet<1 or feet >9) or (inch<0 or inch>11 ):
        print("Luvut eivat ole oikealla valilla!")
    else:
        cm=inch*2.54+feet*12*2.54
        print("Pituus on",cm,"cm.")

if __name__ == '__main__':
    print("Ohjelma muuttaa pituuden senteiksi.")
    tee_pituusmuunnos()
    answer=int(input("Haluatko jatkaa (1 = kylla / 0 = ei)?\n"))
    while(answer==1):
        tee_pituusmuunnos()
        answer = int(input("Haluatko jatkaa (1 = kylla / 0 = ei)?\n"))
    while answer!=1 and answer!=0:
        tee_pituusmuunnos()
        answer = int(input("Haluatko jatkaa (1 = kylla / 0 = ei)?\n"))
    while(answer==0):
        print("Ohjelman suoritus paattyy.")
        sys.exit()







