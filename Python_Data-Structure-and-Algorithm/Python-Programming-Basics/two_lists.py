import os
def main():
    seconds=[]
    cent=[]
    f=input("Mista tiedostosta puhelujen kestot luetaan?\n")
    if os.path.isfile(f)==False:
        print("Virhe tiedoston %s lukemisessa. Ohjelma paattyy."%f)
    else:
        print("Kesto (s)  hinta (snt)")
        myfile=open(f,"r")
        #pure_num(myfile,seconds,cent)
        #exist_nonnum(myfile,seconds,cent)
        cal(myfile,seconds,cent)

def cal(myfile,seconds,cent):
    a=1
    for i in myfile:
        i=i.strip()
        if if_digit(i)==True:
            i=int(i)
            seconds.append(i)
            calculate_cent(i,cent)
            continue
        elif if_digit(i)==False:
            a=0
            break
    if a==1:
        for k in range(len(seconds)):
            print(" %7d %9d" % (seconds[k], cent[k]))
        total_cent = sum(cent)
        total_eur = int(total_cent / 100)
        total_snt = total_cent % 100
        print("---------------------------------------")
        print("Puhelujen yhteishinta on %d eur %d snt." % (total_eur, total_snt))
    else:
        for k in range(len(seconds)):
            print(" %7d %9d" % (seconds[k], cent[k]))
        print("Virheellinen luku tiedostossa. Ohjelma paattyy.")




def pure_num(myfile,seconds,cent):
    total_cent=0
    for i in myfile:
        i = i.strip()
        i = int(i)
        seconds.append(i)
        calculate_cent(i, cent)
    for k in range(len(seconds)):
        print(" %7d %9d"%(seconds[k],cent[k]))
    total_cent=sum(cent)
    total_eur=int(total_cent/100)
    total_snt=total_cent%100
    print("---------------------------------------")
    print("Puhelujen yhteishinta on %d eur %d snt."%(total_eur,total_snt))

def exist_nonnum(myfile,seconds,cent):
        for i in myfile:
            i = i.strip()
            if if_digit(i) == True:
                i = int(i)
                seconds.append(i)
                calculate_cent(i, cent)
            else:
                break
        for k in range(len(seconds)):
            print(" %7d %9d" % (seconds[k], cent[k]))
        print("Virheellinen luku tiedostossa. Ohjelma paattyy.")

def if_digit(x):
    try:
        x=int(x)
        return isinstance(x,int)
    except ValueError:
        return False

def calculate_cent(x,list):
    if (x > 0):
        if (x % 8 == 0):
            a =int (x/ 8)
            list.append(a)
        else:
            a = int((x / 8) + 1)
            list.append(a)
    else:
        a = 0
        list.append(a)


main()