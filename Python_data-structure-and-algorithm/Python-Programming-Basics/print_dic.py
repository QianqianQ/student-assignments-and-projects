import os
def main():
    f=input("Anna kauppatiedoston nimi.\n")
    dic={}
    if os.path.isfile(f) == False:
        print("Tiedoston %s lukeminen ei onnistu.\nOhjelma paattyy."%f)
    else:
        with open(f) as myfile:
            for i in myfile:
                i=i.strip()
                if (' ' in i)==False:
                    print("Virheellinen rivi %s"%i)
                    continue
                else:
                    k,v=i.strip().split()
                    if v.isdigit()==False:
                        print("Virheellinen rivi %s %s"%(k,v))
                    else:
                        if k in dic:
                            dic[k]=int(dic[k])+int(v)
                        else:
                            dic[k]=int(v)
            print("Tuotteita ostettu kootusti:")
            for i in sorted(dic.keys()):
                print("%s %d"%(i,dic[i]))
        myfile.close()

main()