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
        raise NotImplementedError("Implement this method!")        
        
    def return_money(self):
        raise NotImplementedError("Implement this method!")        
    
    def return_married_to(self):
        raise NotImplementedError("Implement this method!")
    
    def get_married(self, human):
        raise NotImplementedError("Implement this method!")
    
    def __str__(self):
        raise NotImplementedError("Implement this method!")
    
def create_humans():
    raise NotImplementedError("Implement this function!")

if __name__ == "__main__":
    create_humans()
    
