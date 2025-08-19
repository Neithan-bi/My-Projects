word = "hello"
for char in word:
    print(char)

for i in range(5,22, 2):
    print(i)
for i in range(10, 0, -1):
    print(i)

stud = {"Name": "John", "Age": 20, "Grade": "A"}
for key in stud:
    print(key, ":", stud[key])
print("Keys:", stud.keys())
print("Values:", stud.values())
print("Items:", stud.items())
print("Iterating over keys:")
for key in stud.keys():
    print(key, ":", stud[key])
