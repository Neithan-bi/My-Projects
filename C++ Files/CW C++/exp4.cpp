#include <iostream>
using namespace std;
class Person {
public:
    string name;
    int age;

    Person(string n, int a) {
        name = n;
        age = a;
    }
};
class Student : public Person {
public:
    int roll;
    Student(Person p, int r) : Person(p.name, p.age) {
        roll = r;
    }
    void show() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << roll << endl;
    }
};
int main() {
    Person p1("Alice", 20);
    Student s1(p1, 101); 
    s1.show();
    return 0;
}
