#include <iostream>
using namespace std;
class Person {
private:
 string name;
 int age;
public:
 Person(string n, int a) {
name=n;
age=a;
}
 // Declare the 'Friend1' class as a friend
 friend class Friend1;
};
class Friend1 {
public:
 // Function to display the private data of Person Class
 void showPersonDetails(const Person& p) {
 cout << "Name: " << p.name << endl;
 cout << "Age: " << p.age << endl;
 }
};
int main() {
 Person person("Alice", 25);
 Friend1 myFriend;
 myFriend.showPersonDetails(person);
 return 0;
}