class Employee:
    company = "Google"
    
    def __init__(self,name,salary,subunit) :
        self.name = name
        self.salary = salary
        self.subunit = subunit
        print("Employee is created")#it will run automatically
    def getDetails(self):
        print(f"The name of employee is {self.name}")
        print(f"The salary of employee is {self.salary}")
        print(f"The subunit of employee is {self.subunit}")
    def getSalary(self):
        print(f"Salary is {self.salary}")#we used instance attributes using self in main function class
    @staticmethod # it is a decorator
    def greet():#u can at least use self argument of use @staticmethod bith at once will give error
        print("Hello sir")  
    @staticmethod
    def time():
        print("Time")  

harry = Employee("Harry",100,"B")
harry.getDetails()
        