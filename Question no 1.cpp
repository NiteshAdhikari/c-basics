 #include <iostream>
using namespace std;

class Student {
private:
    string name;
    int mark1, mark2, mark3;
    int total;
    float average;
    char grade;

public:
    void inputDetails() {
        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter your marks of three subjects: ";
        cin >> mark1 >> mark2 >> mark3;

        if (mark1 < 0 || mark1 > 100 || mark2 < 0 || mark2 > 100 || mark3 < 0 || mark3 > 100) {
            cout << "Invalid marks entered. Please enter values between 0 and 100." << endl;
            exit(0);
        }
    }

    void displayResult() {
        total = mark1 + mark2 + mark3;
        average = total / 3.0;
        grade = (average >= 90) ? 'A' : (average >= 80) ? 'B' : (average >= 70) ? 'C' : (average >= 60) ? 'D' : 'F';
    }

    void finalres() {
        cout << "\nStudent Name: " << name << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student student;
    student.inputDetails();
    student.displayResult();
    student.finalres();
    return 0;
}
