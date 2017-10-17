from humans import Human, create_humans
import unittest
from io import StringIO
from unittest.mock import patch

class Test_Human(unittest.TestCase):
    
    def test_constructor(self):
        """Test constructor. (10p)"""
        firstname = "Teemu"
        lastname = "Teekkari"
        money = 1000
        age = 30
        human_object = Human(firstname, lastname, money, age)
        returned_firstname, returned_lastname = human_object.return_name()
        returned_amount = human_object.return_money()
        returned_age = human_object.return_age()
        self.assertEqual(money, returned_amount, """Your costructor or method return_money() doesn't work correctly. 
        Intializing object with money={} and calling method return_money should return {} not {}""".format(money, money, returned_amount))
        self.assertEqual((firstname, lastname), (returned_firstname, lastname), """Your costructor or method return_name() doesn't work correctly. Method return_name() returned {}, {}.\n
        It should have been returned {}, {}""".format(returned_firstname, returned_lastname, firstname, lastname))
        self.assertEqual(age,returned_age, """Your costructor or method return_age() doesn't work correctly. Method return_age() returned {} not {}""".format(age, returned_age))
        
        
    def test_pay_salary(self):
        """Test method pay_salary. (5p)"""
        money = 1000
        salary = 500
        human_object = Human("Teemu","Teekkari", money, 30)
        human_object.pay_salary(salary)
        returned_amount = human_object.return_money()
        self.assertEqual(money + salary, returned_amount, """Your costructor doesn't work correctly. 
        Intializing object with money={} and calling method pay_salary({}) should return {} not {}""".format(money, salary, money + salary, returned_amount))
        
    def test_buy_something(self):
        """Test method buy_something. (5p)"""
        money = 1000
        cost_of_something = 500
        human_object = Human("Teemu","Teekkari", money, 30)
        human_object.buy_something(cost_of_something)
        returned_amount = human_object.return_money()
        self.assertEqual(money - cost_of_something, returned_amount, """Your costructor doesn't work correctly. 
        Intializing object with money={} and calling method buy_something({}) should return {} not {}""".format(money, cost_of_something, money - cost_of_something, returned_amount))
        
    def test_increment_age(self):
        """Test method increment_age(). (5p)"""
        age = 30
        times_incremented = 5
        human_object = Human("Teemu","Teekkari", 1000, age)
        for i in range(times_incremented):
            human_object.increment_age()
        returned_age = human_object.return_age()
        self.assertEqual(age + times_incremented, returned_age, """Method increment_age() doesn't work correctly. After calling method once age should be {}. Your method returned {}.""".format(age, returned_age))
        
    def test_get_married(self):
        """Test method get_married(). (5p)"""
        human_object = Human("Teemu","Teekkari", 1000, 30)
        human_object_to_marry = Human("Anni", "Arkkari", 1000, 30)
        human_object.get_married(human_object_to_marry)
        returned_answer = human_object.return_married_to()
        human_object_to_marry
        self.assertEqual(returned_answer, human_object_to_marry, """Method get_married() doesn't work correctly. Method return_married_to() returned {}.
        It should have returned {}""".format(returned_answer, human_object_to_marry))
        
        
    @patch('sys.stdout', new_callable=StringIO)
    def test_print(self, mock_stdout):
        """Function create_humans() prints "Onni opiskelija" (5p)"""
        create_humans()
        self.assertEqual(mock_stdout.getvalue(), "Onni Opiskelija\n", "print doesnt'work correctly when calling function create_humans()")
        


if __name__ == "__main__":
    unittest.main(verbosity=2)
