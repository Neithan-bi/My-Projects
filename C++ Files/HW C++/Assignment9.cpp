#include <iostream>
using namespace std;
// Class for Distance Conversion
class DistanceConverter {
public:
 // Convert kilometers to miles
 double convertDistance(double kilometers) {
 return kilometers * 0.621371;
 }
 // Convert meters to kilometers
 double convertDistance(int meters) {
 return meters / 1000.0;
 }
 // Convert meters to miles
 double convertDistance(int meters, bool toMiles) {
 if (toMiles) {
 return meters * 0.000621371;
 }
 return meters / 1000.0;
 }
};
int main() {
 DistanceConverter converter;
 double km = 5.0;
 int meters = 1500;
 // Convert kilometers to miles
 cout << km << " kilometers is equal to " << converter.convertDistance(km) << " miles."
<< endl;
 // Convert meters to kilometers
 cout << meters << " meters is equal to " << converter.convertDistance(meters) << "kilometers." << endl;
 // Convert meters to miles
 cout << meters << " meters is equal to " << converter.convertDistance(meters, true) << "miles." << endl;
 return 0;
}