"""
Scenario-based Python Programs — all solutions in one file.
Run this script to see demos for each section. Functions are provided
so you can import/use specific behaviors in other code.
"""
from typing import List, Tuple, Dict, Set

# -----------------------
# Lists
# -----------------------
def list_grocery_sales_demo():
    sales = [120, 250, 90, 310, 450]
    highest = max(sales)
    lowest = min(sales)
    total = sum(sales)
    return {"sales": sales, "highest": highest, "lowest": lowest, "total": total}

def list_exam_results_demo(marks: List[int]):
    # remove student with lowest marks
    if not marks:
        return []
    marks_copy = marks.copy()
    marks_copy.remove(min(marks_copy))
    return marks_copy

def list_music_playlist_demo(playlist: List[str], new_song: str):
    p = playlist.copy()
    p.append(new_song)         # add new song at end
    if p:
        p.pop(0)               # delete first song
    p.reverse()                # reverse playlist
    return p

# -----------------------
# Tuples
# -----------------------
def tuple_employee_demo(employees: List[Tuple[int,str,int]]):
    # employees is a list of (ID, Name, Salary) tuples
    exists = any(salary > 50000 for (_id,name,salary) in employees)
    return exists

def tuple_library_search(books: List[Tuple[int,str,str]], title: str):
    for bid, btitle, author in books:
        if btitle.lower() == title.lower():
            return (bid, btitle, author)
    return None

def tuple_bank_account_demo(account: Tuple[int,str,float]):
    acc_no, name, balance = account
    low = balance < 1000
    return {"acc_no": acc_no, "name": name, "balance": balance, "low_balance": low}

# -----------------------
# Dictionaries
# -----------------------
def dict_student_grades_demo(grades: Dict[str,int], update_name: str, update_marks: int):
    grades2 = grades.copy()
    grades2[update_name] = update_marks
    # topper
    topper = max(grades2.items(), key=lambda x: x[1])[0]
    above_80 = [name for name, m in grades2.items() if m > 80]
    return {"updated": grades2, "topper": topper, "above_80": above_80}

def dict_shopping_cart_demo(cart: Dict[str,float], add_item: Tuple[str,float], remove_item: str):
    cart2 = cart.copy()
    cart2[add_item[0]] = add_item[1]
    cart2.pop(remove_item, None)
    total = sum(cart2.values())
    return {"cart": cart2, "total": total}

def dict_voting_demo(votes: Dict[str,int], voted_for: str):
    votes2 = votes.copy()
    votes2[voted_for] = votes2.get(voted_for, 0) + 1
    winner = max(votes2.items(), key=lambda x: x[1])[0]
    return {"votes": votes2, "winner": winner}

# -----------------------
# Sets
# -----------------------
def sets_college_clubs(drama: Set[str], music: Set[str]):
    common = drama & music
    unique = drama ^ music
    total_participants = drama | music
    return {"common": common, "unique": unique, "total": total_participants}

def sets_festival_guests(day1: Set[str], day2: Set[str]):
    both = day1 & day2
    only_one_day = day1 ^ day2
    return {"both": both, "only_one_day": only_one_day}

def sets_duplicate_removal(lst: List[int]):
    return list(set(lst))

# -----------------------
# Loops
# -----------------------
def atm_simulation(correct_pin: str = "1234"):
    attempts = 3
    for i in range(attempts):
        pin = input("Enter PIN: ")
        if pin == correct_pin:
            print("Access Granted")
            return True
        else:
            print(f"Incorrect PIN. {attempts - i - 1} attempts left.")
    print("Account blocked")
    return False

def multiplication_table(n: int, upto: int = 10):
    return [n * i for i in range(1, upto+1)]

def primes_1_to_50():
    primes = []
    for num in range(2, 51):
        is_prime = True
        for d in range(2, int(num**0.5)+1):
            if num % d == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(num)
    return primes

# -----------------------
# Conditional Statements
# -----------------------
def grading_system(marks: int):
    if marks >= 90:
        return "A"
    if 75 <= marks <= 89:
        return "B"
    if 50 <= marks <= 74:
        return "C"
    return "Fail"

def job_eligibility(age: int, degree: str):
    if age >= 21 and degree.strip().lower() == "b.tech":
        return "Eligible for Job"
    return "Not Eligible"

def shopping_discount(bill: float):
    if bill < 1000:
        discount = 0
    elif 1000 <= bill <= 5000:
        discount = 0.10
    else:
        discount = 0.20
    discounted_amount = bill * (1 - discount)
    return {"original": bill, "discount_rate": discount, "final_amount": discounted_amount}

# -----------------------
# String Manipulation
# -----------------------
def count_vowels_consonants(s: str):
    vowels = set("aeiouAEIOU")
    v = c = 0
    for ch in s:
        if ch.isalpha():
            if ch in vowels:
                v += 1
            else:
                c += 1
    return {"vowels": v, "consonants": c}

def palindrome_checker(s: str):
    filtered = "".join(ch.lower() for ch in s if ch.isalnum())
    return filtered == filtered[::-1]

def word_counter(sentence: str):
    words = sentence.strip().split()
    return len(words)

# -----------------------
# Functions & Modules
# -----------------------
def factorial(n: int) -> int:
    if n < 0:
        raise ValueError("Negative factorial not defined")
    result = 1
    for i in range(2, n+1):
        result *= i
    return result

def deposit(balance: float, amount: float):
    return balance + amount

def withdraw(balance: float, amount: float):
    if amount > balance:
        raise ValueError("Insufficient funds")
    return balance - amount

def topper_from_dict(grades: Dict[str, int]):
    if not grades:
        return None
    return max(grades.items(), key=lambda x: x[1])[0]

# -----------------------
# File Handling
# -----------------------
import os

def sales_report(filepath: str = "sales.txt"):
    # ensure file exists with sample data if not present
    if not os.path.exists(filepath):
        with open(filepath, "w") as f:
            f.write("\n".join(["120","250","90","310","450"]))
    numbers = []
    with open(filepath, "r") as f:
        for line in f:
            line = line.strip()
            if line:
                try:
                    numbers.append(float(line))
                except ValueError:
                    pass
    total = sum(numbers)
    average = total / len(numbers) if numbers else 0
    return {"numbers": numbers, "total": total, "average": average}

# Hospital management (patients.txt)
PATIENTS_FILE = "patients.txt"

def _ensure_patients_file():
    if not os.path.exists(PATIENTS_FILE):
        sample = [
            "201,Ramesh,45,Diabetes",
            "202,Anitha,29,Flu",
            "203,Manoj,67,Heart Problem"
        ]
        with open(PATIENTS_FILE, "w") as f:
            f.write("\n".join(sample))

def read_all_patients():
    _ensure_patients_file()
    patients = []
    with open(PATIENTS_FILE, "r") as f:
        for line in f:
            parts = [p.strip() for p in line.strip().split(",")]
            if len(parts) >= 4:
                pid = parts[0]
                name = parts[1]
                try:
                    age = int(parts[2])
                except ValueError:
                    age = None
                condition = ",".join(parts[3:])
                patients.append((pid, name, age, condition))
    return patients

def search_patient(pid: str):
    patients = read_all_patients()
    for p in patients:
        if p[0] == pid:
            pid, name, age, condition = p
            extra = ""
            if isinstance(age, int) and age > 60:
                extra = "Senior Citizen – Special Care Required"
            return {"id": pid, "name": name, "age": age, "condition": condition, "note": extra}
    return None

def add_patient(pid: str, name: str, age: int, condition: str):
    _ensure_patients_file()
    # simple append; no duplicate-check to keep implementation short
    with open(PATIENTS_FILE, "a") as f:
        f.write(f"\n{pid},{name},{age},{condition}")
    if age > 60:
        return "Senior Citizen – Special Care Required"
    return "Patient added"

# -----------------------
# Demo runner
# -----------------------
def run_demo():
    print("=== Lists ===")
    print(list_grocery_sales_demo())
    print("Exam results updated:", list_exam_results_demo([78, 45, 62, 30, 88]))
    print("Playlist demo:", list_music_playlist_demo(["SongA","SongB","SongC"], "SongD"))

    print("\n=== Tuples ===")
    employees = [(101,"Asha",48000),(102,"Vikram",52000),(103,"Maya",47000)]
    print("Salary > 50000 exists:", tuple_employee_demo(employees))
    books = [(1,"The Alchemist","Paulo Coelho"), (2,"Inferno","Dan Brown")]
    print("Search book:", tuple_library_search(books, "Inferno"))
    print("Bank:", tuple_bank_account_demo((556677, "Karan", 950.0)))

    print("\n=== Dictionaries ===")
    grades = {"Alice":85,"Bob":78,"Charlie":92}
    print("Grades demo:", dict_student_grades_demo(grades, "Bob", 82))
    cart = {"Pen": 20.0, "Book": 250.0}
    print("Cart demo:", dict_shopping_cart_demo(cart, ("Notebook", 150.0), "Pen"))
    votes = {"Alice":5,"Bob":3}
    print("Voting demo:", dict_voting_demo(votes, "Bob"))

    print("\n=== Sets ===")
    drama = {"Ramesh","Anitha","Karan"}
    music = {"Anitha","Manoj"}
    print("College clubs:", sets_college_clubs(drama, music))
    day1 = {"A","B","C"}; day2 = {"B","D"}
    print("Festival guests:", sets_festival_guests(day1, day2))
    print("Duplicate removal:", sets_duplicate_removal([10,20,20,30,40,10]))

    print("\n=== Loops ===")
    print("Multiplication table of 5:", multiplication_table(5))
    print("Primes 1-50:", primes_1_to_50())
    # ATM simulation is interactive; uncomment to run:
    # atm_simulation()

    print("\n=== Conditionals ===")
    print("Grade for 88:", grading_system(88))
    print("Job eligibility (22, B.Tech):", job_eligibility(22, "B.Tech"))
    print("Discount on 6000:", shopping_discount(6000))

    print("\n=== Strings ===")
    print("Vowels/consonants in 'Hello World':", count_vowels_consonants("Hello World"))
    print("Is 'Level' palindrome?:", palindrome_checker("Level"))
    print("Word count:", word_counter("This is a sample sentence."))

    print("\n=== Functions & Modules ===")
    print("5! =", factorial(5))
    print("Deposit 100 into 500:", deposit(500,100))
    try:
        print("Withdraw 200 from 150:", withdraw(150,200))
    except Exception as e:
        print("Withdraw error:", e)
    print("Topper:", topper_from_dict({"A":55,"B":78,"C":88}))

    print("\n=== File Handling ===")
    print("Sales report:", sales_report())
    print("All patients:", read_all_patients())
    print("Search patient 203:", search_patient("203"))
    print("Add patient result:", add_patient("204","Geeta",65,"Arthritis"))

if __name__ == "__main__":
    run_demo()