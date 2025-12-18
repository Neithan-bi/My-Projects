#include <iostream>
using namespace std;
class Time {
    int hours, minutes;
public:

    Time(int h = 0, int m = 0) {
        hours = h + m / 60;
        minutes = m % 60;
    }
    void show() const {
        cout << hours << " hr " << minutes << " min" << endl;
    }
    Time operator+(const Time& t) const {
        Time temp;
        temp.minutes = minutes + t.minutes;
        temp.hours = hours + t.hours + (temp.minutes / 60);
        temp.minutes %= 60;
        return temp;
    }

    bool operator==(const Time& t) const {
        return (hours == t.hours && minutes == t.minutes);
    }
};
int main() {
    Time t1(2, 50);
    Time t2(1, 25);
    Time total = t1 + t2;  
    cout << "Time 1: "; t1.show();
    cout << "Time 2: "; t2.show();
    cout << "Total : "; total.show();
    if (total == Time(4, 15)) cout << "Total time is equal to 4 hr 15 min\n";
    else cout << "Not equal!\n";
    return 0;
}
