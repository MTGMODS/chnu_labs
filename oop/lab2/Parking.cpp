#include "Parking.h"
#include <iostream>

using namespace std;

ParkingLot::ParkingLot(int _lot_number) : ParkingLot(_lot_number, true, nullptr) {}
ParkingLot::ParkingLot(int _lot_number, bool _available, Car* car) : lotNumber(new int(_lot_number)), isAvailable(new bool(_available)), parkedCar(car) {
    cout << "Parking Lot number " << _lot_number << " initialized." << endl;
}
ParkingLot::~ParkingLot() {
    if (parkedCar) {
        cout << "Car " << parkedCar->getCarModel() << " (" << parkedCar->getCarPlate() << ") unparking from parking lot number " << *lotNumber << endl;
    }
    cout << "Parking lot number " << *lotNumber << " destroyed." << endl;
    delete lotNumber;
    delete isAvailable;
}
void ParkingLot::showParkingLotInfo() {
    cout << "Parking lot number: " << *lotNumber << ", Available: " << (*isAvailable ? "Yes" : "No") << endl;
    if (parkedCar) {
        parkedCar->showCarInfo();
    }
}
void ParkingLot::parkCar(Car* car) {
    if (*isAvailable) {
        parkedCar = car;
        *isAvailable = false;
        cout << "Car parked at parking lot number " << *lotNumber << endl;
    } else {
        cout << "Parking lot number " << *lotNumber << " is not available." << endl;
    }
}
void ParkingLot::unparkCar() {
    if (*isAvailable) {
        cout << "Parking lot number " << *lotNumber << " is already available." << endl;
    } else {
        parkedCar = nullptr;
        *isAvailable = true;
        cout << "Car removed from parking lot number " << *lotNumber << endl;
    }
}
int ParkingLot::getParkingLotNumber() {return *lotNumber;}
bool ParkingLot::getIsAvailable() {return *isAvailable;}
Car* ParkingLot::getParkedCar() {return parkedCar;}

Parking::Parking() : Parking(1) { cout << "(1 parking lot in parking - default value)" << endl; }
Parking::Parking(int _maxParkingSpots) : maxParkingSpots(_maxParkingSpots) {
    cout << "Parking initialized with capacity of " << maxParkingSpots << " parking lots." << endl;
    for (int i = 1; i <= maxParkingSpots; i++) {
        spots.push_back(new ParkingLot(i));
    }
}
Parking::~Parking() {
    for (auto spot : spots) {
        delete spot;
    }
    cout << "Parking destroyed." << endl;
}
ParkingLot* Parking::getParkingLot(int lotNumber) {
    for (auto spot : spots) {
        if (spot->getParkingLotNumber() == lotNumber) {
            return spot;
        }
    }
    cout << "No parking spot found with number " << lotNumber << endl;
    return nullptr;
}
void Parking::showParkingInfo() {
    for (auto spot : spots) {
        spot->showParkingLotInfo();
    }
}
void Parking::parkToFreeLot(Car* car) {
    for (auto spot : spots) {
        if (spot->getIsAvailable()) {
            spot->parkCar(car);
            return;
        }
    }
    cout << "No free lot available to park the car." << endl;
}
void Parking::parkToLotNumber(int lotNumber, Car* car) {
    ParkingLot* spot = getParkingLot(lotNumber);
    if (spot) {
        spot->parkCar(car);
    }
}
void Parking::unParkCar(Car* car) {
    for (auto lot : spots) {
        if (lot->getParkedCar() == car) {
            lot->unparkCar();
            return;
        }
    }
    cout << "The car is not parked in this parking." << endl;
}
void Parking::unParkAllCars() {
    for (auto lot : spots) {
        if (!lot->getIsAvailable()) {
            lot->unparkCar();
            return;
        }
    }
    cout << "The is not parked cars in this parking." << endl;
}