def greet(name):
    print("Hello, " + name)
    
# print(__name__)
if __name__ == "__main__":
    n = (input("Enter : "))
    greet(n)
# it says that if name of the file is main(which means name of the current file) then only it will run we called the function in 07_file and as that file is not the oroginal file it is not executed in the that code