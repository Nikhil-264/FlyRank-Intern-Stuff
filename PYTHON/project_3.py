class Library:
    def __init__(self, listOfBooks):
        self.books = listOfBooks

    def displayAvalaiableBooks(self):
        print("The books present in the library are: ")
        for book in self.books:
            print("\t" + book)

    def borrowBooks(self,bookName):
        if bookName in self.books:
            print(f"You have been issued {bookName}.Please keep it safe and return it within 30 days")
            self.books.remove(bookName)
            return True
        else:
            print("Sorry! We do not have this book.Please wait till the book is returned")
            return False

    def returnBook(self,bookName):
        self.books.append(bookName)
        print("Thanks for returning the book.Hope you enjoyed reading it")

class Student:
    # def __init__(self) -> None:
    #     self.bookList = []
    
    def requestBook(self):
        self.book = input("Enter the name of the book you want to borrow: ")
        return self.book
    
    def returningBook(self):
        self.book = input("Enter the name of the book you want to return: ")
        return self.book

if __name__ == "__main__":
    centralLibrary = Library(["Algorithms" , "Django" , "Python notes","Clrs"])
    student = Student()
    while(True):
        WelcomeMsg = '''\n=====Welcome To Central Library=====
        Please choose the options:
        1. List all the books
        2. Request a book
        3. Return a book
        4. Exit the library'''
        
        print(WelcomeMsg)
        a = int(input("Enter a choice: "))
        if a == 1:
            centralLibrary.displayAvalaiableBooks()
        elif a == 2:
            centralLibrary.borrowBooks(student.requestBook())
        elif a == 3:
            centralLibrary.returnBook(student.returningBook())
        elif a == 4:
            print("Thanks for choosing central library")
            exit()
        else:
            print("Invalid choice!")

