#opening  a file

f = open("demofile.txt", "r")

#reading a file 
print(f.read())
print(f.readline())
print(f.readlines())

#writing a file 

fi = open("demofi.txt", "w")
fi.write("Hey Lkiggas")  
fi.write("Nigamisaloso")
fi.close()

fi = open("demofi.txt", "a")
fi.write("Hey Lkiggas")
fi.write("Nigamisaloso")
fi.close()

#best practice to open a file

with open("demofile.txt", "r") as f:
    content = f.read()
    print(content)

with open("demofi.txt", "a") as fi:
    fi.write("Hey Lkiggas")
    fi.write("Nigamisaloso")
    fi.close()

#working with file path

import os 

print(os.getcwd()) 
print(os.listdir())

#example program

with open("student.txt","w") as file:
    name = input("Enter your name: ")
    age = input("Enter your age: ")
    file.write(f"Name: {name}\nAge: {age}\n")
    print("Student information saved to student.txt")


with open("student.txt","r") as file:
    lines = f.readlines()
    for line in lines:
        print(line.strip())

with open("student.txt","w") as file:
    file.write("Name: Alice\nAge: 21\n")
    file.write("Name: Bob\nAge: 22\n")
    file.write("Name: Charlie\nAge: 23\n")
    file.write("Name: David\nAge: 24\n")
    file.write("Name: Eve\nAge: 25\n")

with open("student.txt","r") as file:
    for line in file:
        print(line.strip())

with open("student.txt","a") as file:
    file.write("Name: Frank\nAge: 26\n")
    file.write("Name: Grace\nAge: 27\n")

with open("demofile.txt", "r") as f:
    text = f.read()
    word_count = len(text.split())
    char_count = len(text)
    print(f"Word Count: {word_count}")
    print(f"Character Count: {char_count}")

with open("copy.txt", "w") as dest_file:
    with open("demofile.txt", "r") as src_file:
        for line in src_file:
            dest_file.write(line)

search = "Alice"
with open("student.txt", "r") as file:
    found = False
    for line in file:
        if search in line:
            print(f"Found: {line.strip()}")
            found = True
    if not found:
        print(f"{search} not found in the file.")







