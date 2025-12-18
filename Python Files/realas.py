age = input("Enter your age:")
if(age<12):
    print("You are a child, so price is 100")
elif(age>12 and age< 59):
    print("You are an adult, so price is 200")
else:
    print("You are a senior citizen, so price is 150")
