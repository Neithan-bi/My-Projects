#include <iostream>
using namespace std;
class subject{
    private:
    int m1;  
    int m2;
public:
    void getMarks() {
        cout << "Enter marks for Subject 1: ";
        cin >> m1;
        cout << "Enter marks for Subject 2: ";
        cin >> m2;
    }

    void displayMarks() {
        cout << "Marks for Subject 1: " << m1 << endl;
        cout << "Marks for Subject 2: " << m2 << endl;
    }
    
};
int main(){
    subject s;
    s.getMarks();
    s.displayMarks();
    return 0;
}