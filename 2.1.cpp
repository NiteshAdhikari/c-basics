 #include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 100) {
        cout << "Not bouncy (All numbers less than 100 are not bouncy)" << endl;
        return 0;
    }

    int increase = 0, decrease = 0;
    int last = number % 10;
    number = number / 10;

    while (number > 0) {
        int current = number % 10;

        if (current < last)
            increase = 1;
        else if (current > last)
            decrease = 1;

        last = current;
        number = number / 10;
    }

    if (increase == 1 && decrease == 1)
        cout << "Bouncy number" << endl;
    else
        cout << "Not bouncy" << endl;

    return 0;
}
