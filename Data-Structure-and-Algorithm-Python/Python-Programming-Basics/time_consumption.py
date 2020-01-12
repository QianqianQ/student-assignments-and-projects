import math
def lue_tunnit():
    amount=int(input("Kuinka monen opiskelijan tiedot annat?\n"))
    while amount<2:
        print("Opiskelijoita pitaa olla vahintaan 2!")
        amount=int(input("Anna opiskelijamaara uudelleen!\n"))
        continue
    print("Anna opiskelijoiden tuntimaarat, kukin omalla rivillaan!")
    time=[]
    for i in range(amount):
        a=float(input())
        time.append(a)
    return time

def laske_keskiarvo(lukuja):
    total_time=0
    for t in lukuja:
        total_time=sum(lukuja)
    ave=total_time/len(lukuja)
    return ave

def laske_keskihajonta(luvut, keskiarvo1):
    pow_sum=0
    a=len(luvut)
    for i in range(a):
        pow_sum += (luvut[i]-keskiarvo1) ** 2
    sd=math.sqrt(pow_sum/(a-1))
    return sd

def montako_suurempaa(lukulista1, alaraja):
    larger_num=0
    for i in range(len(lukulista1)):
        if lukulista1[i]>alaraja:
            larger_num+=1
        else:
            continue
    return larger_num

def montako_pienempaa(lukulista2, ylaraja):
    small_sum=0
    for i in range(len(lukulista2)):
        if lukulista2[i]<ylaraja:
            small_sum+=1
        else:
            continue
    return small_sum

def main():
    print("Tama ohjelma laskee tilastoja opiskelijoiden\nharjoitustehtaviin kayttamista tuntimaarista.")
    time=lue_tunnit()
    renshu=len(time)
    ave=laske_keskiarvo(time)
    sd=laske_keskihajonta(time,ave)
    larger=montako_suurempaa(time,2*ave)
    smaller=montako_pienempaa(time,ave/2)
    large_pro=(larger/renshu)*100
    small_pro=(smaller/renshu)*100
    print("Kaytetyn ajan keskiarvo on %.2f h"%ave)
    print("Kaytetyn ajan keskihajonta on %.2f h"%sd)
    print("Yli %.2f h kaytti %d (%.2f %%) opiskelijaa."%(2*ave,larger,large_pro))
    print("Alle %.2f h kaytti %d (%.2f %%) opiskelijaa." % (ave/2, smaller, small_pro))

main()