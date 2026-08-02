# we can custom the error
def increment(num):
    try:
        return int(num) + 1
    except:
        raise ValueError("NOt")
    
a = increment('w')
print(a)
