#include <iostream>
using namespace std;
class Point {
private:
 int x, y; // Coordinates of the point
public:
 // Simplified constructor without member initializer list
 Point(int xCoord, int yCoord) {
 x = xCoord; // Assign xCoord to x
 y = yCoord; // Assign yCoord to y
 }
 // Overload insertion operator
 void display(ostream& out) const {
 out << "(" << x << ", " << y << ")";
 }
 // Overload extraction operator
 void input(istream& in) {
 in >> x >> y; // Read x and y coordinates from input
 }
};
// Overload the insertion operator for ostream
ostream& operator<<(ostream& out, const Point& p) {
 p.display(out); // Delegate to the display method
 return out; // Return the stream to allow chaining
}
// Overload the extraction operator for istream
istream& operator>>(istream& in, Point& p) {
 p.input(in); // Delegate to the input method
 return in; // Return the stream to allow chaining
}
int main() {
 Point p1(0, 0), p2(3, 4); // Initialize points with specific values
 // Using the extraction operator to input values
 cout << "Enter coordinates for point (x y): ";
 cin >> p1;
 // Using the insertion operator to output the point
 cout << "You entered: " << p1 << endl;
 // Using the insertion operator to output the second point
 cout << "Another point is: " << p2 << endl;
 return 0;
}