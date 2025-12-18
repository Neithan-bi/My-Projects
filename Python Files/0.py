class Book:

    def __init__(self, title, author,price):
        self.title = title
        self.author = author
        self.price = price 

    def display_info(self):
        return f"Title: {self.title}, Author: {self.author}, Price: {self.price}"
    
book1 = Book("1984", "George Orwell", 1000)
print(book1.display_info())

title = input("Enter book title: ")
author = input("Enter book author: ")
price = int(input("Enter price of the book: "))

book1.display_info()