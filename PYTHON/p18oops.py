# class Number:
#     def sum(self):
#         return self.a + self.b


# '''
# pascalcase
# EmployeeName #first letter every word is capital
# camelcase
# isNumeric #first letter samll but every next word starts with capital letter
# '''


# class Remote():
#     pass


# class Player():
#     def moveRight(self):
#         pass

#     def moveLeft(self):
#         pass

#     def moveTop(self):
#         pass


# remote1 = Remote()
# player1 = Player()

# if (remote1.isLeftPressed()):
#     player1.moveLeft()

class Employee:
    company = "Google"
    salary = 100


harry = Employee()
rajni = Employee()

harry.salary = 300
# rajni.salary = 400  # no class atribute as salary #it will give priority to instance attributes than class atributes so instance attributes value written below are printed
print("Harrys Salary", harry.salary)
print("Rajnis Salary ", rajni.salary)
# print(rajni.address)#no such attribute in either instance or class so showing error


# print(harry.company)
# print(rajni.company)
# Employee.company="YouTube" # we can change class atributes value
# print(harry.company)
# print(rajni.company)

# To InstancE attributes can be changed
