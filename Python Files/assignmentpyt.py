
def grocery_store():
    sales = [120, 250, 90, 310, 450]
    highest = max(sales)
    lowest = min(sales)
    total = sum(sales)
    print(f"Highest sale: {highest}")
    print(f"Lowest sale: {lowest}")
    print(f"Total sales: {total}")

def exam_results():
    marks = [85, 92, 78, 65, 88]
    lowest = min(marks)
    marks.remove(lowest)
    print("Updated list after removing lowest marks:", marks)


def music_playlist():
    playlist = ["Song1", "Song2", "Song3", "Song4"]
    playlist.append("Song5")  
    playlist.pop(0)  
    playlist.reverse()
    print("Updated playlist:", playlist)


def employee_records():
    employees = [(101, "Alice", 55000), (102, "Bob", 45000), (103, "Charlie", 60000)]
    for emp in employees:
        if emp[2] > 50000:
            print(f"Employee {emp[0]}: {emp[1]} has salary > 50000")
            break
    else:
        print("No employee with salary > 50000")


def library_system():
    books = [(1, "Python Basics", "Author1"), (2, "Data Structures", "Author2")]
    title_to_search = "Python Basics"
    for book in books:
        if book[1] == title_to_search:
            print(f"Book found: ID {book[0]}, Title {book[1]}, Author {book[2]}")
            break
    else:
        print("Book not found")


def bank_account():
    account = (12345, "John Doe", 800)
    print(f"Account Number: {account[0]}")
    print(f"Name: {account[1]}")
    print(f"Balance: {account[2]}")
    if account[2] < 1000:
        print("Low Balance")
    else:
        print("Balance is sufficient")


def student_grades():
    grades = {"Alice": 85, "Bob": 92, "Charlie": 78, "David": 88}
    grades["Alice"] = 90  # Update marks
    topper = max(grades, key=grades.get)
    print(f"Topper: {topper} with marks {grades[topper]}")
    above_80 = [name for name, mark in grades.items() if mark > 80]
    print("Students with marks above 80:", above_80)


def shopping_cart():
    cart = {"Apple": 50, "Banana": 30, "Orange": 40}
    cart["Grapes"] = 60  # Add new item
    del cart["Banana"]  # Remove item
    total = sum(cart.values())
    print(f"Total bill: {total}")

def voting_system():
    votes = {"CandidateA": 10, "CandidateB": 15, "CandidateC": 8}
    votes["CandidateA"] += 1  # Update vote
    winner = max(votes, key=votes.get)
    print(f"Winner: {winner} with {votes[winner]} votes")

def college_clubs():
    drama = {"Alice", "Bob", "Charlie"}
    music = {"Bob", "David", "Eve"}
    common = drama & music
    unique = drama ^ music
    total = drama | music
    print(f"Common members: {common}")
    print(f"Unique members: {unique}")
    print(f"Total participants: {len(total)}")


def festival_guests():
    day1 = {"Alice", "Bob", "Charlie"}
    day2 = {"Bob", "David", "Eve"}
    both_days = day1 & day2
    one_day = day1 ^ day2
    print(f"Guests on both days: {both_days}")
    print(f"Guests on one day: {one_day}")


def duplicate_removal():
    numbers = [10, 20, 20, 30, 40, 10]
    unique = set(numbers)
    print("List without duplicates:", list(unique))

def atm_simulation():
    pin = "1234"
    attempts = 3
    while attempts > 0:
        entered_pin = input("Enter PIN: ")
        if entered_pin == pin:
            print("Access Granted")
            return
        else:
            attempts -= 1
            print(f"Wrong PIN. {attempts} attempts left.")
    print("Account blocked")


def multiplication_table():
    num = int(input("Enter a number: "))
    for i in range(1, 11):
        print(f"{num} x {i} = {num * i}")


def prime_numbers():
    for num in range(2, 51):
        is_prime = True
        for i in range(2, int(num**0.5) + 1):
            if num % i == 0:
                is_prime = False
                break
        if is_prime:
            print(num, end=" ")
    print()

def grading_system():
    marks = int(input("Enter marks: "))
    if marks >= 90:
        grade = "A"
    elif marks >= 75:
        grade = "B"
    elif marks >= 50:
        grade = "C"
    else:
        grade = "Fail"
    print(f"Grade: {grade}")


def job_eligibility():
    age = int(input("Enter age: "))
    degree = input("Enter degree: ")
    if age >= 21 and degree == "B.Tech":
        print("Eligible for Job")
    else:
        print("Not Eligible")


def shopping_discount():
    bill = float(input("Enter bill amount: "))
    if bill < 1000:
        discount = 0
    elif bill <= 5000:
        discount = 0.1
    else:
        discount = 0.2
    final_bill = bill * (1 - discount)
    print(f"Final bill after discount: {final_bill}")


def vowel_consonant_counter():
    string = input("Enter a string: ").lower()
    vowels = consonants = 0
    for char in string:
        if char.isalpha():
            if char in "aeiou":
                vowels += 1
            else:
                consonants += 1
    print(f"Vowels: {vowels}, Consonants: {consonants}")

def palindrome_checker():
    string = input("Enter a string: ").lower().replace(" ", "")
    if string == string[::-1]:
        print("Palindrome")
    else:
        print("Not a palindrome")

# 3. Word Counter
def word_counter():
    sentence = input("Enter a sentence: ")
    words = sentence.split()
    print(f"Number of words: {len(words)}")


def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n-1)


def deposit(balance, amount):
    return balance + amount

def withdraw(balance, amount):
    if balance >= amount:
        return balance - amount
    else:
        print("Insufficient balance")
        return balance


def find_topper(grades):
    return max(grades, key=grades.get)


def sales_report():
    with open("sales.txt", "r") as file:
        sales = [int(line.strip()) for line in file]
    total = sum(sales)
    average = total / len(sales)
    print(f"Total sales: {total}")
    print(f"Average sales: {average}")

def search_patient(id):
    with open("patients.txt", "r") as file:
        for line in file:
            data = line.strip().split(",")
            if int(data[0]) == id:
                print(f"Patient: {data[1]}, Age: {data[2]}, Condition: {data[3]}")
                if int(data[2]) > 60:
                    print("Senior Citizen – Special Care Required")
                return
    print("Patient not found")

def add_patient():
    id = input("Enter ID: ")
    name = input("Enter Name: ")
    age = input("Enter Age: ")
    condition = input("Enter Condition: ")
    with open("patients.txt", "a") as file:
        file.write(f"{id},{name},{age},{condition}\n")
    print("Patient added")

grocery_store()
exam_results()
music_playlist()
employee_records()
library_system()
bank_account()
student_grades()
shopping_cart()
voting_system()
college_clubs()
festival_guests()
duplicate_removal()
atm_simulation()
multiplication_table()
prime_numbers()
grading_system()
job_eligibility()
shopping_discount()
vowel_consonant_counter()
palindrome_checker()
word_counter()
sales_report()
search_patient(201)
add_patient()
