#include <iostream>
#include <fstream>
using namespace std;


class Vehicle {
protected:
    string registrationNumber;
    string color;

public:
    Vehicle(string reg, string col) {
        registrationNumber = reg;
        color = col;
    }

    void writeToFile() {
        ofstream file("vehicles.txt", ios::app);
        file << "Vehicle - Reg: " << registrationNumber << ", Color: " << color << endl;
        file.close();
    }
};


class Car : public Vehicle {
    int numberOfSeats;

public:
    Car(string reg, string col, int seats) : Vehicle(reg, col) {
        numberOfSeats = seats;
    }

    void writeToFile() {
        ofstream file("vehicles.txt", ios::app);
        file << "Car - Reg: " << registrationNumber
             << ", Color: " << color
             << ", Seats: " << numberOfSeats << endl;
        file.close();
    }
};


class Bike : public Vehicle {
    int engineCapacity;

public:
    Bike(string reg, string col, int capacity) : Vehicle(reg, col) {
        engineCapacity = capacity;
    }

    void writeToFile() {
        ofstream file("vehicles.txt", ios::app);
        file << "Bike - Reg: " << registrationNumber
             << ", Color: " << color
             << ", Engine Capacity: " << engineCapacity << "cc" << endl;
        file.close();
    }
};

int main() {
    Vehicle v("GEN111", "White");
    Car c("ABC123", "Red", 5);
    Bike b("XYZ789", "Black", 150);

    v.writeToFile();
    c.writeToFile();
    b.writeToFile();

    cout << "Vehicle details written to vehicles.txt successfully!" << endl;

    return 0;
}

