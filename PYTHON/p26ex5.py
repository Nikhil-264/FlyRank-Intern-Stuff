# n dimentional vector and calculate the sum and dot product of it
class Vector:
    def __init__(self, vec):
        self.vec = vec

    def __str__(self):
        str1 = ""
        index = 0
        for i in self.vec:
            str1 += f" {i}a{index} +"
            index += 1
        return str1[:-1]

    def __add__(self, vec2):
        newList = []
        for i in range(len(self.vec)):
            newList.append(self.vec[i] + vec2.vec[i])
        return Vector(newList)
    def __mul__(self, vec2):
        # newList = []
        # #This is dot product
        # for i in range(len(self.vec)):
        #     newList.append(self.vec[i] * vec2.vec[i])
        # return Vector(newList)#by this logic we are making it a new vector but dot product is scalar product so valid logic will be
        sum=0
        for i in range (len(self.vec)):
            sum += self.vec[i] * vec2.vec[i]
        return sum
    
    def __len__(self):
        return len(self.vec)
    

v1 = Vector([1, 4, 9])
v2 = Vector([4, 8, 0])
print(v1 + v2)
print(v1 * v2)
print(len(v1) )

