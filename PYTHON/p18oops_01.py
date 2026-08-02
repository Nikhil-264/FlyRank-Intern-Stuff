class Employee:
    company = "Google"

    def getSalary(self):
        print(f"Salary is {self.salary}")#we used instance attributes using self in main function class
    @staticmethod # it is a decorator
    def greet():#u can at least use self argument of use @staticmethod bith at once will give error
        print("Hello sir")  
    @staticmethod
    def time():
        print("Time")      


harry = Employee()
harry.salary=100000
# Employee.getSalary(harry) #same as above statement
harry.getSalary()  # Employee.getSalary(harry) #same as above statement
# when harry is == employee then neew emplyee object formed if self
# self is parameter that passes automatically
harry.greet()
