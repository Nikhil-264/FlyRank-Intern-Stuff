from functools import reduce


def sum(a, b): return a + b


l = [1, 5, 7, 3, 8, 1]
val = reduce(sum,l)# reduce applies a rolling computation to sequentil pair of elemenets it will add 1 and 5 first after that it will add 1 + 5 to 7 and so on till end 
# will do the work of the for loop type function
print(val)
