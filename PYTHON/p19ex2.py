class Calculator:
    def __init__(self, num):
        self.number = num
    def square(self):
        print("Square is",self.number**2)
    def squareRoot(self):
        print("SquareRoot is",self.number**0.5)
    def Cube(self):
        print("Cube is",self.number**3)
    
a = Calculator(3) 
a.square()      
a.squareRoot()      
a.Cube()      

    