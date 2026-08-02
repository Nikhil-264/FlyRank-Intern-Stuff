# import googlesearch using google
from googlesearch import search

query= "daredevil" # Type here what you want to search

for url in search(query):
   print(url)