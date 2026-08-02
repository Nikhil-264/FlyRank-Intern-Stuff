# multiplying complexx numbvers

class Complex:
    def __init__(self, r, i):
        self.real = r
        self.imaginory = i

    def __add__(self, C):
        return Complex(self.real + C.real, self.imaginory + C.imaginory)

    def __mul__(self, C):
        mulReal = self.real*C.real - self.imaginory*C.imaginory
        mulimag = self.real*C.imaginory + self.imaginory*C.real
        return Complex(mulReal, mulimag)

    def __truediv__(self, C):
        divreal = (self.real*C.real + self.imaginory*C.imaginory) / \
            (C.real**2 + C.imaginory**2)
        divimag = (-self.real*C.imaginory + self.imaginory *
                   C.real) / (C.real**2 + C.imaginory**2)
        return Complex(divreal, divimag)

    def __str__(self):
        return f"{self.real} + {self.imaginory}i"


c1 = Complex(3, 2)
c2 = Complex(1, 7)
print(c1 + c2)
print(c1 * c2)
print(c1 / c2)

