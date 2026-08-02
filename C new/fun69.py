def find_numbers():
    numbers=[]
    x=range(48,99,1)
    for n in x:
        square = n**2
        cube = n**3

        digits = set(str(square)+str(cube))
        if len(digits)==10:
            numbers.append(n)
    return numbers

numbers = find_numbers()
print(numbers)