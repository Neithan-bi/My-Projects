#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
    Person(string n, int a) {
        name = n;
        age = a;
    }
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
public:
    int studentID;
    Student(string n, int a, int id) : Person(n, a), studentID(id) {}
    void displayStudentInfo() {
        displayInfo();
        cout << "Student ID: " << studentID << endl;
    }
};

int main() {
    Student student("Alice", 20, 12345);
    student.displayStudentInfo();
    return 0;
}