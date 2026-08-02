# SYNTAX
class Employee:  # Base class
    company = "google"

    def showDetails(self):
        print("Company : ", self.company)


class Programmer(Employee):  # Derived class
    language = "Python"
    company = "YouTube"

    def getLanguage(self):
        print("Language is : ", self.language)

    def showDetails(self):
        print("Company is : ", self.company)

# each class will print its own function if name is same or in derived class class will use base class function if no function is prsent in derived class with same name
e = Employee()
e.showDetails()
p = Programmer()
p.showDetails() 
print(p.company)
#This is example of single inheritance