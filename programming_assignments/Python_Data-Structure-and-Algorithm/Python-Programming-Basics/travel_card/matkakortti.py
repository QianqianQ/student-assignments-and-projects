class Matkakortti:

    def __init__(self, haltijan_nimi):
        self.name=haltijan_nimi
        self.balance=0.0
        self.valid=True

    def kerro_omistaja(self):
        return self.name

    def kerro_saldo(self):
        return self.balance

    def onko_validi(self):
        if self.valid==True:
            return True
        else:
            return False

    def kasvata_saldoa(self, lisays):
        if lisays>0:
            self.balance+=lisays
        else:
            self.balance=self.balance+0

    def poista_kaytosta(self):
        self.valid=False

    def nollaa_saldo(self):
        self.balance=0.0

    def tee_matka(self, onko_seutu):
        if onko_seutu==True:
            if self.balance-4<0 or self.valid==False:
                return False
            else:
                self.balance -= 4
                return True
        else:
            if self.balance-2<0 or self.valid==False:
                return False
            else:
                self.balance-=2
                return True

    def __str__(self):
        if self.valid==True:
            return "Omistaja: %s, saldo: %.2f eur.\nKortti on kaytossa."%(self.name,self.balance)
        else:
            return "Omistaja: %s, saldo: %.2f eur.\nKortti ei ole kaytossa."%(self.name,self.balance)



