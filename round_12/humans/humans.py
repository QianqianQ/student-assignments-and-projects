class Human():
    def __init__(self, first_name, last_name, money, age):
        self.__first_name = first_name
        self.__last_name = last_name
        self.__money = money
        self.__age = age
        self.__married_to = None

    def return_name(self):
        return self.__first_name, self.__last_name
        
    def increment_age(self):
        self.__age += 1
        
    def return_age(self):
        return self.__age
    
    def buy_something(self, money):
        if self.__money < money:
            return False
        else:
            self.__money -= money
            return True

    def pay_salary(self, amount):
        self.__money += amount
              
        
    def return_money(self):
        return self.__money      
    
    def return_married_to(self):
        return self.__married_to
    
    def get_married(self, human):
        self.__married_to = human
        human.__married_to= self
    
    def __str__(self):
        return "{} {}".format(self.__first_name,self.__last_name)
    
def create_humans():
    human1 = Human("Teemu","Teekkari",0,30)
    human2 = Human("Onni","Opiskelija",1000,22)
    human3 = Human("Anni","Arkkari",2000,23)
    human1.buy_something(100)
    human2.buy_something(500)
    human1.pay_salary(2500)
    human1.get_married(human3)
    human3.increment_age()
    print(human2)
    return human1,human2,human3

if __name__ == "__main__":
    human1,human2,human3 = Human.create_humans()
    
