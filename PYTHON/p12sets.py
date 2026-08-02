a = {1, 3, 5, 6, 1, 3}
print(a)  # as a set it wont repeat elements while printing
print(type(a))
b = {}  # this syntax will create emply dictionary not empty sets
# empty set can be created using below syntax
print(type(b))  # will print dictionary
b = set()
print(type(b))
# adding members
b.add(6)
b.add(7)
b.add(9)
b.add(12)
b.add(12)
b.add(12)
b.add(12)
b.add(12)  # adds 12 only once
# b.add([2,5,7]) we cant add list in the set as it is not hashable but can add tupples
b.add((2, 5, 7))  # added as one element
# b.add(2, 5, 7)  # cant add like this
print(b)
print(len(b))
# sets are unsorted,unordered,unindexed
# cant change emlements in the set
# cant set dupliavte values

# operations on sets
b.add(68)#adds element
print(len(b)) #gives lenght of set
print(b)
b.remove(68) #removes element
print(b)
print(b.pop())#removes random element
print(b.pop())
print(b)
# b.clear() #empties the set
print(b.union({8,11}))#it gives union of this provided set and b
print(b.intersection({12}))
#returns intersection between two sets