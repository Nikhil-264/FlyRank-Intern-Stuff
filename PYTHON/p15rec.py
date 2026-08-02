# factorial code using recurrtion
def Factorial(n):
    if n == 0:
        return 1
    else:
        return (n*Factorial(n-1))


print("Enter the number")
num = int(input())
print("The factororial is " , Factorial(num))
