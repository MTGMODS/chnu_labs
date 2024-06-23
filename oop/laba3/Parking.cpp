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
ParkingLot::ParkingLot(const ParkingLot& other): lotNumber(new int(*other.lotNumber)), isAvailable(new bool(*other.isAvailable)), parkedCar(other.parkedCar) {
    cout << "Depp Copy constructor Parking Lot was called!" << endl;
}
ParkingLot::ParkingLot(ParkingLot&& other) : lotNumber(other.lotNumber), isAvailable(other.isAvailable), parkedCar(other.parkedCar) {
    other.lotNumber = nullptr;
    other.isAvailable = nullptr;
    other.parkedCar = nullptr;
    cout << "Move constructor Parking Lot was called!" << endl;
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
        cout << "Car " << parkedCar->getCarModel() << " parked at parking lot number " << *lotNumber << endl;
    } else {
        cout << "Parking lot number " << *lotNumber << " is not available." << endl;
    }
}
void ParkingLot::unparkCar() {
    if (*isAvailable) {
        cout << "Parking lot number " << *lotNumber << " is already available." << endl;
    } else {
        cout << "Car " << parkedCar->getCarModel() << " removed from parking lot number " << *lotNumber << endl;
        parkedCar = nullptr;
        *isAvailable = true;
    }
}
int ParkingLot::getParkingLotNumber() {return *this->lotNumber;}
bool ParkingLot::getIsAvailable() {return *this->isAvailable;}
Car* ParkingLot::getParkedCar() {return this->parkedCar;}

Parking::Parking() : Parking(1) { cout << "(1 parking lot in parking - default value)" << endl; }
Parking::Parking(int _maxParkingLots) : maxParkingLots(_maxParkingLots) {
    cout << "Parking initialized with capacity of " << maxParkingLots << " parking lots." << endl;
    for (int i = 1; i <= maxParkingLots; i++) {
        Lots.push_back(new ParkingLot(i));
    }
    totalParkingLots += _maxParkingLots;
}
Parking::~Parking() {
    for (auto spot : Lots) {
        delete spot;
    }
    totalParkingLots -= maxParkingLots;
    cout << "Parking destroyed." << endl;
}

Parking::Parking(const Parking& other) : maxParkingLots(other.maxParkingLots) {
    for (auto spot : other.Lots) {
        Lots.push_back(new ParkingLot(*spot));
    }
    cout << "Deep Copy constructor Parking was called." << endl;
}
Parking::Parking(Parking&& other) : maxParkingLots(other.maxParkingLots), Lots(move(other.Lots)) {
    other.Lots.clear();
    cout << "Move constructor Parking was called!" << endl;
}

int Parking::totalParkingLots = 0;
int Parking::getTotalParkingLots() {
    return totalParkingLots;
}

ParkingLot* Parking::getParkingLot(int lotNumber) {
    for (auto spot : Lots) {
        if (spot->getParkingLotNumber() == lotNumber) {
            return spot;
        }
    }
    cout << "No parking spot found with number " << lotNumber << endl;
    return nullptr;
}
void Parking::showParkingInfo() {
    for (auto spot : Lots) {
        spot->showParkingLotInfo();
    }
}
void Parking::parkToFreeLot(Car* car) {
    for (auto spot : Lots) {
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
    for (auto lot : Lots) {
        if (lot->getParkedCar() == car) {
            lot->unparkCar();
            return;
        }
    }
    cout << "The car is not parked in this parking." << endl;
}
void Parking::unParkAllCars() {
    for (auto lot : Lots) {
        if (!lot->getIsAvailable()) {
            lot->unparkCar();
            return;
        }
    }
    cout << "The is not parked cars in this parking." << endl;
}