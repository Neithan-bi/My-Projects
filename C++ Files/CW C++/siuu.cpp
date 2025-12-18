#include <iostream>
using namespace std;
int main() {
    cout << "Enter num1 :" << endl;
    int num1;
    cin >> num1;
    cout << "Enter num2 :" << endl;
    int num2;   
    cin >> num2;
    char nig;
    cout << "Enter operation (add, sub, mul, div):" << endl;
    cin >> nig;
    switch (nig)
    {
    case '+': cout << num1 + num2;
         break;
    case '-': cout << num1 - num2;
         break;
    case '*': cout << num1 * num2;
         break;
    case '/': cout << num1 / num2;
         break;
    default:
    cout << "Invalid operation";
        break;
    }
}