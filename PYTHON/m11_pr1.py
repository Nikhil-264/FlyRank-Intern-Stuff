# Write a program to open 3 files 1.txt and so on. iF  any of these files are not present a message without exiting the program must be printed
def readFile(filename):
    try:
        with open(filename, "r") as f:
            print(f.read())
    except FileNotFoundError:
        print(f"File {filename} not found")
        
readFile("1.txt")
readFile("2.txt") # if theis file doest exist then we have to print a message can do it usinf try n except
readFile("3.txt")