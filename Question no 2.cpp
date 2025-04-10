 #include <iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    friend void  compareTwoCircles(Circle c1, Circle c2);
};

void  compareTwoCircles(Circle c1, Circle c2) {
    float area1 = 3.14 * c1.radius * c1.radius;
    float area2 = 3.14 * c2.radius * c2.radius;

    if (area1 > area2) {
        cout << "The first circle has a larger area." << endl;
    } else if (area2 > area1) {
        cout << "The second circle has a larger area." << endl;
    } else {
        cout << "Both circles have the same area." << endl;
    }
}

int main() {
    float r1, r2;

    cout << "Enter radius of the first circle: ";
    cin >> r1;

    cout << "Enter radius of the second circle: ";
    cin >> r2;

    Circle circle1 = Circle(r1);
    Circle circle2 = Circle(r2);

     compareTwoCircles(circle1, circle2);

    return 0;
}
