class Employee:
    company="Bharat Gas"
    salary = 4500
    salarybonus = 600
    # totalSalary = salary+salarybonus
    @property 
    def totalSalary(self):
        return self.salarybonus + self.salary
    @totalSalary.setter
    def totalSalary(self,val):
        self.salarybonus = val - self.salary
    
e=Employee()
print(e.totalSalary)# we had to write as e.totalSalary() but as it a property now we dont have to use ()
e.totalSalary=5620
print(e.salarybonus)#we changed the value of totalSalary to get proper addition od salary and salarybonus setter changed the value of salarybonus 
