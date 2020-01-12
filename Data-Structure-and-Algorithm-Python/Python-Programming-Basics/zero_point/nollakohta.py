import math


def pyyda_kertoimet():
    a = int(input(("Anna arvot yhtalon kertoimille a, b ja c.\n")))
    b = int(input())
    c = int(input())
    return a, b, c


def pyyda_lahtotietoja():
    a = float(input("Anna valin alaraja.\n"))
    b = float(input("Anna valin ylaraja.\n"))
    c = float(input("Anna haluttu tarkkuus.\n"))
    return a, b, c


def funktion_arvo(a, b, c, x):
    y = a * ((math.sin(x)) ** 2) + b * math.sin(x) + c * x
    return y

def if_midpoint_zero(a,b,c,midpoint):
    if funktion_arvo(a,b,c,midpoint)==0:
        return True
    else:
        return False

def start_middle_compare(a,b,c,start,middle):
    if funktion_arvo(a,b,c,middle)*funktion_arvo(a,b,c,start)<0:
        return True
    else:
        return False

def middle_end_compare(a,b,c,middle,end):
    if funktion_arvo(a,b,c,middle)*funktion_arvo(a,b,c,end)<0:
        return True
    else:
        return False

def main():
    print("Ohjelma laskee yhtalon")
    print("a * (sin(x)) ** 2  + b * sin(x) + c * x = 0")
    print("yhden ratkaisun likiarvon haluamallasi valilla.")
    a1, b1, c1 = pyyda_kertoimet()
    ala, yla, tarkkuus = pyyda_lahtotietoja()
    if ala > yla:
        print("Antamasi vali on tyhja.")
    elif funktion_arvo(a1, b1, c1, ala) * funktion_arvo(a1, b1, c1, yla) > 0:
        print("Funktion arvo on valin molemmissa paissa samanmerkkinen.")
        print("Menetelma ei sovi talle valille.")
    elif funktion_arvo(a1, b1, c1, ala) == 0.0:
        print("***")
        print("Ratkaisu on x = {:.4f}".format(ala))
    elif funktion_arvo(a1, b1, c1, yla) == 0.0:
        print("***")
        print("Ratkaisu on x ={:.4f}".format(yla))
    else:
        start_point=ala
        end_point=yla
        interval = abs(end_point - start_point)
        mid_point = (abs(end_point - start_point) / 2) + start_point
        while (interval>2*tarkkuus):
                if if_midpoint_zero(a1,b1,c1,mid_point)==True:
                    result = funktion_arvo(a1, b1, c1, mid_point)
                    print("Funktion arvo pisteessa %.4f on %.4f." % (mid_point, result))
                    print("***")
                    print("Ratkaisu on x = %.4f" % mid_point)
                    break
                elif (if_midpoint_zero(a1,b1,c1,mid_point)==False) and (start_middle_compare(a1,b1,c1,start_point,mid_point)==True):
                    result=funktion_arvo(a1,b1,c1,mid_point)
                    print("Funktion arvo pisteessa %.4f on %.4f." % (mid_point, result))
                    interval=abs(mid_point-start_point)
                    end_point=mid_point
                    mid_point=abs(end_point-start_point)/2+start_point
                    continue
                elif (if_midpoint_zero(a1,b1,c1,mid_point)==False) and (middle_end_compare(a1,b1,c1,mid_point,end_point)==True):
                    result = funktion_arvo(a1, b1, c1, mid_point)
                    print("Funktion arvo pisteessa %.4f on %.4f." % (mid_point, result))
                    interval=abs(end_point-mid_point)
                    start_point=mid_point
                    mid_point= (abs(end_point-start_point)/2)+start_point
                    continue

        if funktion_arvo(a1, b1, c1,mid_point)!=0:
            print("***")
            print("Ratkaisu on x = %.4f"%mid_point)


main()
