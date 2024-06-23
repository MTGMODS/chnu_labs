#include "Car.h"
#include <iostream>
#include <string>

using namespace std;

Car::Car() : car_model(new string("Unknown")), car_plate(new string("Unknown")) {}
Car::Car(string _car_model) : Car(_car_model, "Unknown") {}
Car::Car(string _car_model, string _car_plate) : car_model(new string(_car_model)), car_plate(new string(_car_plate)) {}
Car::Car(const Car &other) : car_model(new string(*other.car_model)), car_plate(new string(*other.car_plate)) {
    cout << "Deep Copy constructor Car was called" << endl;
}
Car::Car(Car &&other) : car_model(other.car_model), car_plate(other.car_plate) {
    other.car_model = nullptr;
    other.car_plate = nullptr;
    cout << "Move constructor Car was called" << endl;
}
Car& Car::operator=(const Car& other) {
    if (this == &other) {
        return *this;
    }
    *car_model = *other.car_model;
    *car_plate = *other.car_plate;
    return *this;
}
Car::~Car() {
    cout << "Car " << *car_model << " (" << *car_plate << ") destroy!" << endl;
    delete car_model;
    delete car_plate;
}


void Car::showCarInfo() const {cout << "Car model: " << *car_model << ", number plate: " << *car_plate << endl;}
string Car::getCarModel() const {return *this->car_model;}
string Car::getCarPlate() const {return *this->car_plate;}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << "Car model: " << car.getCarModel() << ", number plate: " << car.getCarPlate() << endl;
    return out;
}
std::istream& operator>>(std::istream& in, Car& car) {
    std::cout << "Enter car model:" << endl;
    std::getline(in, *car.car_model);
    std::cout << "Enter car number plate:" << endl;
    std::getline(in, *car.car_plate);
    return in;
}




