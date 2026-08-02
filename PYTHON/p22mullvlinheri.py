class Person:
    country = "India"

    def takeBreath(self):
        print("I'm Breathing")


class Employee(Person):
    company = "Honda"

    def __init__(self):
        super().__init__()
        print("OK")

    def getSalary(self):
        print(f"salary is {self.salary}")

    def takeBreath(self):
        super().takeBreath()  # Will run for super class
        print("I am lucky")


class Programmer(Employee):
    company = "Fiverr"

    def __init__(self):
        super().__init__()
        print("cool")

    def getSalary(self):
        print("No")

    def takeBreath(self):
        super().takeBreath()  # Will run for super class
        print("I am lucky to breath")


p = Person()
# p.takeBreath()
e = Employee()
e.takeBreath()
# pr = Programmer()
# pr.takeBreath()
