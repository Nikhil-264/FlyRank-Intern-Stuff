#  WRITE A program to write a table of  number using comprehention
num = int(input("Enter your number : "))

table = [num * i for i in range(1,11)]
# t = "\n".join(table)
print(table)

# sentence = "\n".join(l)
# print(sentence)

num = int(input("Enter your number: "))

table = [f"{i} x {num} = {num * i}\n" for i in range(1, 11)]
# print(table)

print(''.join(table))
