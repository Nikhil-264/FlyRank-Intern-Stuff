a="nikhil"
b='''nikhil's car said "helllo" nikhil'''#use of different quotes
print(b)
print (a +b)
# print(b-a) cant do this
print (a[1])
#a[3]="d" we cant do this
#@slicing
print(a[0:3]) # index 3 not including
# print(a[2:3]) 
print (b[-4])
# print (b[-3])
# print (b[-2])# negative index is exactly equal to (normal index - lenght of string)
print(a[2:]) # if not given last index it will go upto last index
print(a[:2])# it will from start to 1  
print(a[3:-5]) 
print(b[1:20:3]) #it will print every 3rd letter between 1 and 20  
print(b[1::3])# it will print till end by skiiping 2 values means printing every 3rd letter  
#string functions
print(len(a)) # gives lenght of the string
print(a.endswith("il")) # tells whether it ends with given string or not gives boolean output
print(b.endswith("il"))
print(a.count("l"))#tells how many times given string has appeared in the main string apperaed
print(b.count("lll"))
print(b.count("s "))
print(b.capitalize())#capitalizes the first letter of the string
print(b.find("helll0")) #return index of the given string present inbut gives index of the first appearence the main string if not returns -1
print(b.replace("nikhil","amruta"))
print(b.replace("nikhil","tony"))
#escape sequeance charatcters #same as C
story = "\tnikhil studys in iit kharagpur \n\the has four year course"
print(story)
#\n -> newline character
#\t -> tab