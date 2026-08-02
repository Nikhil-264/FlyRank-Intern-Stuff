# try:
#     i = int(input("ENter the numver : "))
#     c = 1 / i
# except Exception as e:
#     print(e)
# else:
#     print("Success") #its like if else if there is no error it will print else statemment

# Try with finally:
# finally will run regardless of error found or not in abive exapmle

try:
    i = int(input("ENter the numver : "))
    c = 1 / i
except Exception as e:
    print(e)
    exit()
finally:
    print("Success")
print("End if the code")  #if code shows error of not even if we end the code with exit statemenrt fianlly statement will still executed as shown
# sample input 3 w
    