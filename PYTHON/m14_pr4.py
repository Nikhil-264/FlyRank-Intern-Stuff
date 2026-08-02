# write a prigram ot displey a/b wehre a and b are integers of b =0 display infinite by hab=nding the ZeroDivisionError

a = int(input("Enter a: "))
b = int(input("Enter b: "))
try:
    print(a / b)
except:
    print("Infinite")
