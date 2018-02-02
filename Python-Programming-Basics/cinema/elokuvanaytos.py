class Elokuvanaytos:
    MINIMUM = 3

    def __init__(self, elokuva, ajankohta, sali, riveja, paikkoja_rivilla):
        self.name=elokuva
        self.time=ajankohta
        self.hall=sali
        if riveja<3:
            self.rows=3
        else:
            self.rows=riveja
        if paikkoja_rivilla<3:
            self.place=3
        else:
            self.place=paikkoja_rivilla

        self.list=[[0 for i in range(self.place)] for j in range(self.rows)]

    def kerro_nimi(self):
        return self.name

    def kerro_esitysaika(self):
        return self.time

    def kerro_esityssali(self):
        return self.hall

    def varaa_paikka(self, rivi, paikka):
        if rivi>self.rows or paikka>self.place:
            return False

        if self.list[rivi-1][paikka-1]==1:
            return False
        else:
            self.list[rivi-1][paikka-1]=1
            return True

    def varaa_paikat(self, rivi, ensimmainen, viimeinen):
        if rivi>self.rows or (ensimmainen<1 or ensimmainen>self.place) or viimeinen>self.place:
            return False
        else:
            not_valid=0
            for i in range(ensimmainen-1,viimeinen):
                if self.list[rivi][i]==1:
                    not_valid=1
                    break
                else:
                    continue
            if not_valid==1:
                return False
            else:
                for i in range(ensimmainen-1,viimeinen):
                    self.list[rivi][i]=1
                return True

    def kerro_varauskartta(self):

        for i in range(self.rows-1,-1,-1):
            print("%d:"%(i+1),end='')
            for j in range(self.place-1):
                if self.list[i][j]==0:
                    print("-",end='')
                else:
                    print("X",end='')

            if self.list[i][self.place-1]==0:
                print("-")
            else:
                print("X")
        return 0


    def kerro_paikkojen_kokonaismaara(self):
        return self.place*self.rows

    def montako_varattu(self):
        reserved=0
        for i in range(self.rows):
            for j in range(self.place):
                if self.list[i][j]==1:
                    reserved+=1
                else:
                    continue
        return reserved


    def __str__(self):
        return self.time+" "+self.name+" "+self.hall+" "+"varatuu "+str(self.montako_varattu())+"/"+str(self.kerro_paikkojen_kokonaismaara())



