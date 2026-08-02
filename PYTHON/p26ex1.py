class C2dVector:
    def __init__(self, i, j):
        self.icap = i
        self.jcap = j

    def __str__(self):
        return f"{self.icap}i + {self.jcap}j"


class C3dVec(C2dVector):
    def __init__(self, i, j, k):
        super().__init__(i, j)
        self.kcap = k

    def __str__(self):
        return f"{self.icap}i + {self.jcap}j + {self.kcap}k"


V2d = C2dVector(1, 3)
v3d = C3dVec(1, 9, 5)

print(V2d)
print(v3d)
