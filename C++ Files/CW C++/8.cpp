#include <iostream>
using namespace std;
int main() {
    int marks;
    cout << "Enter your marks: ";
    cin >> marks;
    if (marks >= 90) {
        cout << "A+";
    } else if (marks >= 80) {
        cout << "A";
    } else if (marks >= 75) {
        cout << "B";
    } else if (marks >= 40) {
        cout << "C";
    } else if (marks >= 33) {
        cout << "D";
    } else {
        cout << "F";
    }
}
