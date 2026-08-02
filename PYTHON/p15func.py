#this is example of function
def percent(marks):
    return sum(marks)/4

marks = [34,87,45,97]
percentage = percent(marks)
print(percentage)

def greet(name="Stranger"):#it will use stranger when we do not pass any argument in function when we call it
    print("Hello " + name)
    
    
greet("Nikhil") # will print helo nikhil
greet() #Will print hello starnger
#Default Parameter Value

#Introduction to strip function
s1= '     Hello World!     hello sun'
print('After Strip:', s1.strip()) #it will remove extra spaces in the text present at end and start pf the string