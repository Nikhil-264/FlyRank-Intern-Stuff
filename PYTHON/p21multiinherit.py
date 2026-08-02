# 2 parant 1 child
class Employee:
    company = "Visa"
    eCode = 120


class Freelancer:
    company = "Fiverr"
    level = 0
    def UpgradeLevel(self):
        self.level += 1


class Programmer(Employee, Freelancer):
    name = "Rohit"


p = Programmer()
p.UpgradeLevel()
print(p.level)
print(p.company) #Will print visa because  employee is first parameter
