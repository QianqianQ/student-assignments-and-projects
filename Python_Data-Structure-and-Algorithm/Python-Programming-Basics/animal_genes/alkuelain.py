import copy
class Alkuelain:
    GEENIEN_MAARA = 10
    PIENIN_GEENI = 0
    SUURIN_GEENI = 5
    def __init__(self, annettu_nimi, geenilista):
        self.name=annettu_nimi
        self.genelist=[]
        a=1
        for i in range(len(geenilista)):
            if (geenilista[i]<0 or geenilista[i]>5) or len(geenilista)!=10:
                a=0
                break
            else:
                continue
        if a==1:
            #self.genelist=geenilista[:]
            for i in range(len(geenilista)):
                self.genelist.append(geenilista[i])
        else:
            for i in range(10):
                self.genelist.append(0)

    def kerro_nimi(self):
        return self.name

    def kerro_perima(self):
        return self.genelist

    def mutaatio(self, geenin_numero, uusi_geeni):
        if (uusi_geeni>=0 and uusi_geeni<=9) and (uusi_geeni>=0 and uusi_geeni<=5):
            self.genelist[geenin_numero]=uusi_geeni
            return True
        else:
            return False

    def klooni(self, kloonin_nimi):
        new1=Alkuelain(kloonin_nimi,self.genelist)
        return new1

    def pariudu(self, toinen_alkuelain, jalkelaisen_nimi):
        new2=copy.deepcopy(self)
        new2.name=jalkelaisen_nimi
        for i in range(len(toinen_alkuelain.genelist)):
            if i%2!=0:
                new2.genelist[i]=toinen_alkuelain.genelist[i]
        return new2


    def __str__(self):
        return "Alkuelain nimi: %s, perima: %s"%(self.kerro_nimi(),str(self.genelist))



