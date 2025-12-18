import re
def is_valid_emp_id(s: str) -> bool:
    return bool(re.fullmatch(r'EMP\d{4}', s))
if __name__ == '__main__':
    emp_id = input("Enter employee ID: ").strip()
    print("Valid ID" if is_valid_emp_id(emp_id) else "Invalid ID")