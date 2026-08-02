with open("sample.txt") as f:
    content = f.read()
    
words=["donkey","ok","king","lol"]    
for word in words:
    content = content.replace(word,"censored")

with open("sample.txt",'w') as f:
        f.write(content)
        #replaces the every word in the words word with gives signs