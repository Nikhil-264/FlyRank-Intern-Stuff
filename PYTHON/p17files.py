# # #use open function to read the content in the file
# # #by default the mode is r
# # f = open('sample.txt','r')
# # # data=f.read() # cant read a same document twice 
# # # print(data)
# # # data=f.read(5)#reads first 5 character from the file
# # data = f.readline() # will read only first line of the file
# # data = f.readline() # whwn called again will read the next line in file
# # print(data)
# # f.close()
# # # text file comes in primary file
# # #pdf and jpg type files come in binary files
# # # to use read 'r' 'w' 'a' '+' add b when using for binary file like 'rb' 'wb' etc

# # # writing in file
# # f = open('another .txt','w')
# # f.write("Please add this to file")# if file not existing code will generate a file and add the text to it and w will write in file from styart by erasing old data in it
# # f.close()
# f = open('another .txt','w') #it will just append to the file 
# f.write("OK")
# f.write("OK")
# f.write("OK")
# f.write("OK") #will print OK 4 times as we ran it before closing the file
# f.close()

#using with statement
#the best way to open and close the file automatically is the with statement

with open ("this text")as f:
    f.read()
    #this will automatically close the file

