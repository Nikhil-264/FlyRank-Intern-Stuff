class Number:
    def __init__(self, num1):
        self.num = num1

    def __add__(self, num2):
        print("Lets add")
        return self.num + num2.num
    def __mul__(self, num2):
        print("Lets multiply")
        return self.num * num2.num
    
# p1 + p2 --> p1 __add__ p2
# p1 - p2 --> p1 __sub__ p2
# p1 * p2 --> p1 __mul__ p2
# p1 / p2 --> p1 __truediv__ p2
# p1 // p2 --> p1 __floordiv__ p2


n1 = Number(4)
n2 = Number(5)
sum = n1 + n2
mul = n1 * n2
print(sum)
print(mul)
