import os
def main():
    total_score=0
    f=input("Anna sanat sisaltava tiedosto.\n")
    if os.path.isfile(f)==False:
        print("Virhe tiedoston %s lukemisessa. Ohjelman suoritus paattyy."%f)
    else:
        a=1
        myfile=open(f,"r")
        for i in myfile:
            line=i.strip()
            word=line.split("-")
            if len(word)<4 or word[3].isdigit()==False:
                print("Virheellinen rivi:",line)
            else:
                print("%s_____%s" % (word[0], word[2]))
                shuru = input("")
                if shuru.lower() == word[1].lower():
                    total_score += int(word[3])
                    print("Oikein, sait %d pistetta!" % int(word[3]))
                    print("Sinulla on yhteensa %d pistetta" % total_score)
                else:
                    print("Ei natsannut!")
                    print("Sinulla on yhteensa %d pistetta" % total_score)
        print("Game over! Sait yhteensa %d pistetta." % total_score)



def all_valid(myfile):
    for i in myfile:
        i=i.strip()
        seg1.append(i.split("-")[0])
        seg2.append(i.split("-")[1])
        seg3.append(i.split("-")[2])
        score.append(int(i.split("-")[3]))

    for k in range(len(seg1)):
        print("%s_____%s"%(seg1[k],seg3[k]))
        shuru=input("")
        if shuru.lower()==seg2[k].lower():
            total_score+=score[k]
            print("Oikein, sait %d pistetta!"%score[k])
            print("Sinulla on yhteensa %d pistetta"%total_score)
        else:
            print("Ei natsannut!")
            print("Sinulla on yhteensa %d pistetta" % total_score)
    print("Game over! Sait yhteensa %d pistetta."%total_score)

main()