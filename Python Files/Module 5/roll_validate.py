import re

# Input roll number
roll_number = input("Enter student roll number: ")

# Regular expression: Two uppercase letters + three digits
pattern = r'^[A-Z]{2}\d{3}$'

# Validate using re.match()
if re.match(pattern, roll_number):
    print("Valid Roll Number")
else:
    print("Invalid Roll Number")
