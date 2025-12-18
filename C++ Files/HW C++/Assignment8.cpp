#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void createFile(string filename) {
 ofstream file(filename);
 string data;
 cout << "Enter data (type 'exit' to finish):\n";
 while (getline(cin, data) && data != "exit") {
 file << data << endl;
 }
 file.close();
 cout << "File created successfully.\n";
}
void readFile(string filename) {
 ifstream file(filename);
 if (!file) {
 cout << "File not found.\n";
 return;
 }
 string line;
 cout << "File contents:\n";
 while (getline(file, line)) {
 cout << line << endl;
 }
 file.close();
}
void deleteFile(string filename) {
 if (remove(filename.c_str()) == 0) {
 cout << "File deleted successfully.\n";
 } else {
 cout << "File not found.\n";
 }
}
int main() {
 string filename;
 int choice;
 cout << "Enter filename (with extension): ";
 getline(cin, filename);
 do {
 cout << "\nMenu:\n";
 cout << "1. Create File\n";
 cout << "2. Read File\n";
 cout << "3. Delete File\n";
 cout << "4. Exit\n";
 cout << "Choose an option: ";
 cin >> choice;
 cin.ignore(); // Clear newline from input buffer
 switch (choice) {
 case 1:
 createFile(filename);
 break;
 case 2:
 readFile(filename);
 break;
 case 3:
 deleteFile(filename);
 break;
 case 4:
 cout << "Exiting.\n";
 break;
 default:
 cout << "Invalid choice. Try again.\n";
 }
 } while (choice != 4);
 return 0;
}