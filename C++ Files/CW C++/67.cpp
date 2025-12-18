#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student {
private:
int student_id;
string student_name;
double student_gpa;
public:
Student(int id, const string& name, double gpa) {
	student_id = id;
	student_name = name;
	student_gpa = gpa;
	cout << "Student object for " << student_name << " created." << endl;
}
~Student() {
	cout << "Student object for " << student_name << " destroyed." << endl;
}
void display() const {
	cout << "ID: " << student_id << ", Name: " << student_name << ", GPA: " << student_gpa << endl;
}
};
int main() {

vector<Student> students;

students.push_back(Student(101, "Alice", 3.8));
students.push_back(Student(102, "Bob", 3.5));
students.push_back(Student(103, "Charlie", 4.0));

cout << "\n--- All Students ---" << endl;
for (const Student& student : students) {
student.display();
}


return 0;
}