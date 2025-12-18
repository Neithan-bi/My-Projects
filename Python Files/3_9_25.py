class student:
    def __init__(self, name, age, grade):
        self.name = name
        self.age = age
        self.grade = grade

    def display_info(self):
        print(f"Name: {self.name}, Age: {self.age}, Grade: {self.grade}")
student1 = student("Teja", 20, "A")
student1.display_info()
student2 = student("John", 22, "B")
student2.display_info()