import random
randNumber = random.randint(1, 100)
print(randNumber)
Guess = 0
userGuess = None
while (userGuess != randNumber):
    userGuess = int(input("Enter your guess : "))
    if (userGuess == randNumber):
        print("You guessed it right !")
    else:
        if(userGuess>randNumber):
            print("Try smaller Number!")
        else:
            print("Try bigger Number !")
        # print("You guessed it wrong !")
    
    Guess += 1    

print(f"You took {Guess} guesses to indentify the number")

# with open ("hiscore.txt", 'r')as f:
#     hiscore = int(f.read())
    
# if(Guess < hiscore):
#     print("You have just broken the hiscore!")
#     with open ("hiscore.txt", 'w') as f:
#         f.write(str(Guess))
        
with open("hiscore.txt", 'r') as f:
    hiscore = int(f.read())

if Guess < hiscore:
    print("You have just broken the hiscore!")
    with open("hiscore.txt", 'w') as f:
        f.write(str(Guess))


    