# with open ("poem.txt") as f:
#     t=f.read()
#     if 'twinkle' in t:
#         print('yes')
#     else:
#         print ('no')
def game():
    return 445


score = game()
with open('hiscore.txt') as f:
    hiscorestr = (f.read())

if hiscorestr == '':
    with open('hiscore.txt', 'w') as f:
        f.write(str(score))

elif score > int(hiscorestr):
    with open('hiscore.txt', 'w') as f:
        f.write(str(score))
