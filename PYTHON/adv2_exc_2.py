try:
    a = int(input("Enter the numebr : "))
    c = 1 / a
    print(c)
    
except ValueError as e:
    print("Enter valid input")
    
except ZeroDivisionError as e:
    print("Make sure you are not dividing by 0 ")
    
print("THanks")
# sample input  a , 0 , 1