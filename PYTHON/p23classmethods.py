class Emoployee:
    company = "Camel"
    salary = 100
    location="delhi"
    
    # def changeSalary(self,sal):
    #     self.salary= sal  #This methos=d will add instance attribute it wont change value of class attribute
    # def ChangeSalary(self,sal):
    #     self.__class__.salary=sal#This will change class attributes value
    @classmethod #its a decorator that can use functions as paramaters
    def changeSalary(cls,sal):#cls is function input parameter
        cls.salary=sal#instaead of doing what we did above we can use classmethods #it will cahnge value of class attributes

e = Emoployee()
print(e.salary)
e.changeSalary(232)
print(e.salary) #changed due to instance attribute addition
print(Emoployee.salary)
# e.ChangeSalary(456)
print(Emoployee.salary)#changed due to using __class__