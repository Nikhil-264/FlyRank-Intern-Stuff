a = [3, 5, 7, 3, 7, 34, 1, 0, 5]
# b = []
# for i in a:
#     if (i > 5):
#         b.append(i)
# print(b)
# c = sorted(b)
# print(c)
b = {i for i in a} # works same as the above commented code
print(b)  # b is set 
