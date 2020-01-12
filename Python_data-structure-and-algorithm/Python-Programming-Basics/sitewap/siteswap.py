def onko_validi(siteswap):
    list=[]
    same_value=0
    for i in range(len(siteswap)):
        value=(int(siteswap[i])+i)%3
        list.append(value)
    for x in list:
        if list.count(x)==1:
            continue
        else:
            same_value=1
            break
    if same_value==0:
        return True
    else:
        return False


def oikea_korkeus(siteswap, maxkorkeus):
    exceed_max=0
    for i in range(len(siteswap)):
        value=int(siteswap[i])
        if value>maxkorkeus:
            exceed_max=1
            break
        else:
            continue
    if exceed_max==1:
        return False
    else:
        return True

def oikea_maara(siteswap, pallot):
    sum=0
    for i in range(len(siteswap)):
        sum+=int(siteswap[i])

    ave=sum/len(siteswap)

    if ave==pallot:
        return True
    else:
        return False

def generoi_siteswappeja(pallot, maxkorkeus, jakso):
    list=[]
    for luku in range(10**(jakso-1),10**jakso):
        mahdollinen_sitewap=str(luku)
        if int(mahdollinen_sitewap[0])>=1 and onko_validi(mahdollinen_sitewap) and oikea_korkeus(mahdollinen_sitewap,maxkorkeus) and oikea_maara(mahdollinen_sitewap,pallot):
            list.append(mahdollinen_sitewap)
        if len(list)==10:
            break
    return list

def main():
    balls=int(input("Monenko pallon kuvio (1-9)?\n"))
    while balls<1 or balls>9:
        balls = int(input("Monenko pallon kuvio (1-9)?\n"))
    print("Heiton maksimikorkeus (%d-9)?"%balls)
    max_height=int(input())
    while max_height<balls or max_height>9:
        print("Heiton maksimikorkeus (%d-9)?" % balls)
        max_height = int(input())
    peroid_length=int(input("Jaksonpituus (1-5)?\n"))
    list=generoi_siteswappeja(balls,max_height,peroid_length)
    print("Siteswapit:")
    for i in range(len(list)):
        print(list[i])

main()

