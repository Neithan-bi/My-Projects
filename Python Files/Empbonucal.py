salary = float(input("Enter salary: "))
service = int(input("Enter years of service: "))

if(salary >= 50000 and service >= 10 ):
    bonus = salary * 0.10
elif(salary >= 30000 and service >= 5):
    bonus = salary * 0.05
else:
    bonus = 0
print("Bonus is: ", bonus)
