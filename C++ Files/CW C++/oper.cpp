#include <iostream>
using namespace std;
int main() {
 int a = 7;
 int b = 4;
 int bitwise_and = a & b;
 int bitwise_or = a | b;
 int bitwise_xor = a ^ b;
 int bitwise_not = ~b;
 int left_shift = 5 << 2;
 int right_shift = 16 >> 2;
 cout << "AND: " << bitwise_and << endl;
 cout << "OR: " << bitwise_or << endl;
 cout << "XOR: " << bitwise_xor << endl;
 cout << "NOT b: " << bitwise_not << endl;
 cout << "Left Shift: " << left_shift << endl;
 cout << "Right Shift: " << right_shift << endl;
 return 0;
}