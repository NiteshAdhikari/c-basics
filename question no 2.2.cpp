 #include <iostream>
using namespace std;

class MaxFinder {
public:
    int findMax(int a, int b) {
        return (a > b) ? a : b;
    }

    float findMax(float a, float b) {
        return (a > b) ? a : b;
    }

    int findMax(int a, int b, int c) {
        if (a >= b && a >= c)
            return a;
        else if (b >= a && b >= c)
            return b;
        else
            return c;
    }

    float findMax(int a, float b) {
        return (a > b) ? a : b;
    }
};

int main() {
    MaxFinder max;

    int a, b, c;
    float x, y;
    int result1, result3;
    float result2, result4;

    cout << "Enter two integers: ";
    cin >> a >> b;
    result1 = max.findMax(a, b);
    cout << "Max between " << a << " and " << b << ": " << result1 << endl;

    cout << "\nEnter two float numbers: ";
    cin >> x >> y;
    result2 = max.findMax(x, y);
    cout << "Max between " << x << " and " << y << ": " << result2 << endl;

    cout << "\nEnter three integers: ";
    cin >> a >> b >> c;
    result3 = max.findMax(a, b, c);
    cout << "Max among " << a << ", " << b << ", and " << c << ": " << result3 << endl;

    cout << "\nEnter an integer and a float: ";
    cin >> a >> y;
    result4 = max.findMax(a, y);
    cout << "Max between " << a << " and " << y << ": " << result4 << endl;

    return 0;
}
