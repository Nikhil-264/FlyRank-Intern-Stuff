# TRY AND EXCEPT
while (True):
    print("Press q to quit")
    a = input("Enter a Number : ")
    if a == 'q':
        break
    try:
        a = int(a)
        if a > 6:
            print("Yes")
    except Exception as e:
        print("Exception1 is :")
        print(e)
    except ValueError as e:
        print("Exception2 is :")
        print(e)
    except ZeroDivisionError as e:
        print("Exception3 is :")
        print(e)
        
print("Thank you")
