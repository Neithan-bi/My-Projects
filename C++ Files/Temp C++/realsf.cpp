#include <iostream>
using namespace std;
class Employee { //Base Class
protected:
 string name;
 int empId;
public:
 void getEmployeeDetails() {
 cout << "Enter employee ID: ";
 cin >> empId;
 cin.ignore(); // clear input buffer
 cout << "Enter employee name: ";
 getline(cin, name);
 }
 void displayEmployeeDetails() {
 cout << "Employee ID: " << empId << endl;
 cout << "Employee Name: " << name << endl;
 }
};
// Derived class for salary details, virtual base class to avoid ambiguity
class Salary : virtual public Employee {
protected:
 double basicPay;
 double hra; // House Rent Allowance
public:
 void getSalaryDetails() {
 cout << "Enter basic pay: ";
 cin >> basicPay;
 cout << "Enter HRA: ";
 cin >> hra;
 }
 double getGrossPay() {
 return basicPay + hra;
 }
};
// Derived class for deductions, virtual base class to avoid ambiguity
class Deductions : virtual public Employee {
protected:
 double tax;
 double providentFund;
public:
 void getDeductionDetails() {
 cout << "Enter tax amount: ";
 cin >> tax;
 cout << "Enter provident fund: ";
 cin >> providentFund;
 }
 double getTotalDeductions() {
 return tax + providentFund;
 }
};
// Derived class to calculate net pay
class NetPay : public Salary, public Deductions {
public:
 void calculateNetPay() {
 double gross = getGrossPay();
 double deductions = getTotalDeductions();
 double netPay = gross - deductions;
 cout << "--- Employee Pay Details ---";
 displayEmployeeDetails();
 cout << "Gross Pay: " << gross << endl;
 cout << "Total Deductions: " << deductions << endl;
 cout << "Net Pay: " << netPay << endl;
 }
};
int main() {
 NetPay emp;
 emp.getEmployeeDetails(); // Input employee info
 emp.getSalaryDetails(); // Input salary details
 emp.getDeductionDetails(); // Input deductions
 emp.calculateNetPay(); // Display net pay
 return 0;
}