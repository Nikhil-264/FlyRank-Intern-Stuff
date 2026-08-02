#  Store a multoplication table generated in problem 3 in file name Tnbles.txt
# import m13_pr3
num = int(input("Enter number: "))
table = [num * i for i in range(1, 11)]
# print(str(table))
with open("tables.txt", "a") as f:
    f.write(str(table))
    f.write('\n')
