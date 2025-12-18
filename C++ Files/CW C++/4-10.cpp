#include <iostream>
using namespace std;

class Dad {
    private:
        string name;
        int age;
    public:
        Dad(string n, int a) {
            name = n;
            age = a;
        }
        void show() {
            cout << "Dad's name: " << name << ", Age: " << age << endl;
        }
};

class Mom {
    private:
        string name;
        string occupation;
    public:
        Mom(string n, string o) {
            name = n;
            occupation = o;
        }
        void show() {
            cout << "Mom's name: " << name << ", Occupation: " << occupation << endl;
        }
};

class Child : public Dad, public Mom {
    private:
        string name;
        string hobby;
    public:
        Child(string n, string dn, int da, string mn, string mo, string h) 
            : Dad(dn, da), Mom(mn, mo) {
            name = n;
            hobby = h;
        }
        void show() {
            cout << "Child's name: " << name << ", Hobby: " << hobby << endl;
            Dad::show();
            Mom::show();
        }
};

int main() {
    string childName, dadName, momName, momOccupation, childHobby;
    int dadAge;

    cout << "Enter Child's name: ";
    cin >> childName;
    cout << "Enter Dad's name: ";
    cin >> dadName;
    cout << "Enter Dad's age: ";
    cin >> dadAge;
    cout << "Enter Mom's name: ";
    cin >> momName;
    cout << "Enter Mom's occupation: ";
    cin >> momOccupation;
    cout << "Enter Child's hobby: ";
    cin >> childHobby;

    Child c(childName, dadName, dadAge, momName, momOccupation, childHobby);
    c.show();

    return 0;
}