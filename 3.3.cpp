 #include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int roll;
    string name;
    int marks;
};

int main() {
    Student s[100];
    int count = 0;

    ifstream inFile("students.txt");
    while (inFile >> s[count].roll >> s[count].name >> s[count].marks) {
        if (s[count].marks < 0 || s[count].marks > 100) {
            cout << "Error: Invalid marks for student " << s[count].name << endl;
            return 1;
        }
        count++;
    }
    inFile.close();

    char choice;
    cout << "Do you want to add a new student? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Enter roll number: ";
        cin >> s[count].roll;

        cout << "Enter name: ";
        cin >> s[count].name;

        cout << "Enter marks: ";
        cin >> s[count].marks;

        if (s[count].marks < 0 || s[count].marks > 100) {
            cout << "Error" << endl;
            return 1;
        }

        count++;
    }

    ofstream outFile("students.txt");
    for (int i = 0; i < count; i++) {
        outFile << s[i].roll << " " << s[i].name << " " << s[i].marks << endl;
    }
    outFile.close();

    cout << "Student records saved." << endl;

    return 0;
}
