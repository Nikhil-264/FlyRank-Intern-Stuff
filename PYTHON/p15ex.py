# def celtofarh(n):
#     return (n*(9/5)) + 32


# def sumof_n_rec(n):
#     if n == 1:
#         return n
#     else:
#         return n+sumof_n_rec(n-1)


# celsius = float(input('Enter the temperature in Celsius: '))
# print(celtofarh(celsius))

# p = sumof_n_rec(celsius)
# print(p)
# s1= '     Hello World!     hello sun'
# def remove_and_split(string,word):
#     new = string.replace(word,"")
#     return new.strip()

# print(remove_and_split(s1,"Hello"))
def multitable(n):
    for i in range(1, 11):
        print(n*i)


n = int(input("Enter number: "))
multitable(n)
