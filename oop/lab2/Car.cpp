#include "Car.h"
#include <iostream>

using namespace std;

Car::Car() : car_model(new string("Unknown")), car_plate(new string("Unknown")) {}
Car::Car(string _car_model) : Car(_car_model, "Unknown") {}
Car::Car(string _car_model, string _car_plate) : car_model(new string(_car_model)), car_plate(new string(_car_plate)) {}
Car::~Car() {
    cout << "Car " << *car_model << " (" << *car_plate << ") destroy!" << endl;
    delete car_model;
    delete car_plate;
}

void Car::showCarInfo() {cout << "Car model: " << *car_model << ", number plate: " << *car_plate << endl;}
string Car::getCarModel() {return *car_model;}
string Car::getCarPlate() {return *car_plate;}


