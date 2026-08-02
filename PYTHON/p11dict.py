mydict = {
    "key": "value",
    "fast": "have great speed",
    "slow": "'move slowly'",
    "quick": "'be quick'",
    "marks": [1, 3, 5],
    "dict2": {"f": 1, "g": 4}
}  # dont forget comas
print(mydict['fast'])
print(mydict['marks'])
print(mydict['dict2'])  # to print whole dictionary
# to print a part/memnber of dictionary in nested dictionary
print(mydict['dict2']["f"])
mydict['dict2']["f"] = 45
print(mydict['dict2']["f"])
# ther is no order like arrays in the dictioary
# we can change the value of the member it is mutabel you can use duplicate keys
#methods for dictionary
print(type(mydict.keys()))
print(mydict.keys()) # prints keys of the dictioanry
print(mydict.values()) # prints values assigned to the keys in the given order
print(mydict['dict2'].values())
updatedict={
    "hola":"ok",
    "THIK":"k",
}
mydict.update(updatedict)#update sthe dictionary by appending in the original dictionary 
print(mydict)
print(mydict.items())
print(mydict.get("hola2"))#it return none of key is not present in dictioanry that is difference between .get and normal approach
print(mydict["hola2"])#throws error as hola2 not present in dictionary
print(mydict.get("hola"))#it return none of key is not present in dictioanry that is difference between .get and normal approach
print(mydict["hola"])#throws error as hola2 not present in dictionary