# # # # # i = 1
# # # # # number = int(input("Enter number: "))
# # # # # # while i<11:
# # # # # #     print(number*i)
# # # # # #     i=i+1

# # # # # # using for loop
# # # # # for i in range(1, 11):
# # # # #     # print(number * i)
# # # # #     # print(str(number) + "X" + str(i) + "=" + str(number*i))
# # # # #     # f string use in loop
# # # # #     print(f"{number}X{i}={number*i}")
# # # # l1 = ["harry", "sohan", "sachin", "rahul"]

# # # # for name in l1:
# # # #     if name.startswith("s"  ):
# # # #         print("Hello " + name)

# # # # is prime or not
# # # prime = True
# # # num = int(input("Enter number : "))
# # # for i in range(2, num):
# # #     if num % i == 0:
# # #         prime = False
# # #         break
# # # if prime:
# # #     print("Prime")
# # # else:
# # #     print("Not prime")

# # # finding factorial of a number
# # # using while
# # # num = int(input("Enter number : "))

# # # i = num -1
# # # fact=num
# # # while i != 1:
# # #     fact = fact*i
# # #     i -= 1

# # # using for loop
# # num = int(input("Enter number : "))
# # fact = 1
# # for i in range(1, num+1):
# #     fact = fact * i

# # print(f"factorial of a {num} is {fact}")


# # printing star pattern
# # n =int ( input ("enter the value"))
# # for row in range( n ) :
# #     print("*" * (row+1))

# # different pattern
# n = int(input("enter the value"))
# for i in range(n):
#         print(" "*(n-i-1),end="")
#         print( "*" * (2*i+1),end="")#end used for not to change the lineS
#         print(" "*(n-i-1))
# print for 3
# ***
# * *
# ***
# for 5
# *****
# *   *
# *   *
# *   *
# *****
n = int(input("enter the value: "))

# for i in range(n):
# print("*" * n)
# for j in range(n-2):
#     print("*", " "*(n-4), "*")
# print("*" * n)


# for i in range(n):
#     if (i == 0 or i == n-1):
#         print("*"*n)
#     print("*"+" "*(n-2)+"*")

i = 1
while i <= n:
    if (i == 1 or i == n):
        print("*"*n)
    else:
        print("*"+" "*(n-2)+"*")
    i += 1
