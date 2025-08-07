#include <iostream>
using namespace std;

int main() {
    char l;
    cin >> l;
    
    if (l == 'A' || l == 'E' || l == 'I' || l == 'O' || l == 'U' ||
        l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u') {
        cout << "vowel";
    } else {
        cout << "Not a vowel";
    }
    
    return 0;
}