class Train:
    def __init__(self, name, fare, seats):
        self.name = name
        self.fare = fare
        self.seats = seats

    def getStatus(self):
        print(f"name is {self.name}")
        print(f"seats avalable are  {self.seats}")

    def fareInfo(self):
        print("The price of tickef is ₹", self.fare)

    def bookTicket(self):
        if (self.seats > 0):
            print("Seat booked. Sat is", self.seats)
            self.seats = self.seats - 1
        else:
            print("Try Tatkal")
    def cancelTicket(self,seatNo):
        pass
                


intercity = Train("Intercity Express :14078", 90, 300)
intercity.getStatus()
intercity.fareInfo()
intercity.bookTicket()
intercity.getStatus()
