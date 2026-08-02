class Programmer:
    company = "Microsoft"

    def __init__(self, name, product):
        self.name = name
        self.product = product

    def getInfo(self):
        print("name", self.name, "and product is ", self.product)


harry = Programmer("Harry", "Skype")
Alka = Programmer("Alka", "GitHub")
harry.getInfo()
Alka.getInfo()
