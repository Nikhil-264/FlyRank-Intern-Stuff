class Sample:
    a = "harry"
    def __init__(self,name):#when we write anyhting else in this line instead of self the code will run but it will beahve as a normal parameter
        self.name = name
        
obj = Sample("Harry")        
obj.a="Vicky"
print(obj.name)