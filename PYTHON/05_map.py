def square(num):
    return num * num


a = [1, 3, 5]
# method 
l2 = []
for item in a:
    l2.append(square(item)) 
print(l2)
# Method 2 using map
print(list(map(square,a))) # We didnt need to make empty list

