#include "Parking.h"

ParkingLot::ParkingLot(int _lot_number) : ParkingLot(_lot_number, true, nullptr) {}
ParkingLot::ParkingLot(int _lot_number, bool _available, Car* car) : lotNumber(new int(_lot_number)), isAvailable(new bool(_available)), parkedCar(car) {
    std::cout << "Parking Lot number " << _lot_number << " initialized." << std::endl;
}
ParkingLot::~ParkingLot() {
    if (parkedCar) {
        std::cout << "Car " << parkedCar->getCarModel() << " (" << parkedCar->getCarPlate() << ") unparking from parking lot number " << *lotNumber << std::endl;
    }
    std::cout << "Parking lot number " << *lotNumber << " destroyed." << std::endl;
    delete lotNumber;
    delete isAvailable;
}
ParkingLot::ParkingLot(const ParkingLot& other) : lotNumber(new int(*other.lotNumber)), isAvailable(new bool(*other.isAvailable)), parkedCar(other.parkedCar) {
    std::cout << "Deep Copy constructor Parking Lot was called!" << std::endl;
}
ParkingLot::ParkingLot(ParkingLot&& other) : lotNumber(other.lotNumber), isAvailable(other.isAvailable), parkedCar(other.parkedCar) {
    other.lotNumber = nullptr;
    other.isAvailable = nullptr;
    other.parkedCar = nullptr;
    std::cout << "Move constructor Parking Lot was called!" << std::endl;
}
ParkingLot& ParkingLot::operator=(const ParkingLot& other) {
    if (this == &other) {
        return *this;
    }
    *lotNumber = *other.lotNumber;
    *isAvailable = *other.isAvailable;
    parkedCar = other.parkedCar;
    return *this;
}
int ParkingLot::getParkingLotNumber() { return *lotNumber; }
bool ParkingLot::getIsAvailable() { return *isAvailable; }
Car* ParkingLot::getParkedCar() { return parkedCar; }
void ParkingLot::showParkingLotInfo() {
    std::cout << "Parking lot number: " << *lotNumber << ", Available: " << (*isAvailable ? "Yes" : "No") << std::endl;
    if (parkedCar) {
        parkedCar->showCarInfo();
    }
}
void ParkingLot::parkCar(Car* car) {
    if (*isAvailable) {
        parkedCar = car;
        *isAvailable = false;
        std::cout << "Car " << parkedCar->getCarModel() << " parked at parking lot number " << *lotNumber << std::endl;
    } else {
        std::cout << "Parking lot number " << *lotNumber << " is not available." << std::endl;
    }
}
void ParkingLot::unparkCar() {
    if (*isAvailable) {
        std::cout << "Parking lot number " << *lotNumber << " is already available." << std::endl;
    } else {
        std::cout << "Car " << parkedCar->getCarModel() << " removed from parking lot number " << *lotNumber << std::endl;
        parkedCar = nullptr;
        *isAvailable = true;
    }
}

ParkingVIPLot::ParkingVIPLot(int _lot_number) : ParkingLot(_lot_number) {}
ParkingVIPLot::ParkingVIPLot(int _lot_number, bool _available, Car* car) : ParkingLot(_lot_number, _available, car) {}
ParkingVIPLot::~ParkingVIPLot() {}

ParkingVIPLot::ParkingVIPLot(const ParkingVIPLot& other) : ParkingLot(other) {
    std::cout << "Deep Copy constructor VIP Parking Lot was called!" << std::endl;
}
ParkingVIPLot::ParkingVIPLot(ParkingVIPLot&& other) : ParkingLot(std::move(other)) {
    std::cout << "Move constructor VIP Parking Lot was called!" << std::endl;
}
ParkingVIPLot& ParkingVIPLot::operator=(const ParkingVIPLot& other) {
    if (this == &other) {
        return *this;
    }
    ParkingLot::operator=(other); // Call base class assignment operator
    std::cout << "Operator= VIP Parking Lot was called!" << std::endl;
    return *this;
}

void ParkingVIPLot::showParkingLotInfo() {
    std::cout << "VIP Parking lot number: " << *lotNumber << ", Available: " << (*isAvailable ? "Yes" : "No") << std::endl;
    if (parkedCar) {
        parkedCar->showCarInfo();
    }
}

int Parking::totalParkingLots = 0;

Parking::Parking() : Parking(1, 0) { std::cout << "(1 parking lot and 1 vip parking - default value)" << std::endl; }

Parking::Parking(int _maxParkingLots, int _maxVIPParkingLots) : maxParkingLots(_maxParkingLots), maxVIPParkingLots(_maxVIPParkingLots) {
    cout << "Parking initialized with capacity of " << maxParkingLots << " standard parking lots and " << maxVIPParkingLots << " VIP parking lots." << endl;
    for (int i = 1; i <= maxParkingLots; i++) {
        Lots.push_back(new ParkingLot(i));
    }
    for (int i = 1; i <= maxVIPParkingLots; i++) {
        Lots.push_back(new ParkingVIPLot(i));
    }
    totalParkingLots += _maxParkingLots + _maxVIPParkingLots;
}


Parking::~Parking() {
    for (auto spot : Lots) {
        delete spot;
    }
    totalParkingLots -= maxParkingLots + maxVIPParkingLots;
    cout << "Parking destroyed." << endl;
}

Parking::Parking(const Parking& other) : maxParkingLots(other.maxParkingLots), maxVIPParkingLots(other.maxVIPParkingLots) {
    std::cout << "Deep Copy constructor Parking was called." << std::endl;
    for (auto spot : other.Lots) {
        if (spot->getIsAvailable()) {
            Lots.push_back(new ParkingLot(*spot));
        } else {
            Lots.push_back(new ParkingVIPLot(*static_cast<ParkingVIPLot*>(spot)));
        }
    }
}


Parking::Parking(Parking&& other) : maxParkingLots(other.maxParkingLots), maxVIPParkingLots(other.maxVIPParkingLots), Lots(std::move(other.Lots)) {
    other.Lots.clear();
    std::cout << "Move constructor Parking was called!" << std::endl;
}

Parking& Parking::operator=(const Parking& other) {
    if (this == &other) {
        return *this;
    }
    std::cout << "Operator= Parking was called." << std::endl;
    for (auto& lot : Lots) {
        delete lot;
    }
    Lots.clear();

    maxParkingLots = other.maxParkingLots;
    maxVIPParkingLots = other.maxVIPParkingLots;

    for (auto spot : other.Lots) {
        if (spot->getIsAvailable()) {
            Lots.push_back(new ParkingLot(*spot));
        } else {
            Lots.push_back(new ParkingVIPLot(*static_cast<ParkingVIPLot*>(spot))); // Safe cast since we know the type
        }
    }
    return *this;
}

int Parking::getTotalParkingLots() {
    return totalParkingLots;
}

void Parking::showParkingInfo() {
    for (auto spot : Lots) {
        spot->showParkingLotInfo();
    }
}

ParkingLot* Parking::getParkingLot(int lotNumber) {
    for (auto spot : Lots) {
        if (spot->getParkingLotNumber() == lotNumber) {
            return spot;
        }
    }
    std::cout << "No parking spot found with number " << lotNumber << std::endl;
    return nullptr;
}

void Parking::parkToFreeLot(Car* car) {
    for (auto spot : Lots) {
        if (spot->getIsAvailable()) {
            spot->parkCar(car);
            return;
        }
    }
    std::cout << "No free lot available to park the car." << std::endl;
}

void Parking::parkToLotNumber(int lotNumber, Car* car) {
    ParkingLot* spot = getParkingLot(lotNumber);
    if (spot) {
        spot->parkCar(car);
    }
}

void Parking::parkToVIPLot(Car* car) {
    for (auto spot : Lots) {
        ParkingLot* lot = spot;
        if (lot && !lot->getIsAvailable()) {
            continue; // Skip standard lots
        }
        ParkingVIPLot* vipSpot = static_cast<ParkingVIPLot*>(spot);
        if (vipSpot && vipSpot->getIsAvailable()) {
            vipSpot->parkCar(car);
            cout << "Car " << car->getCarModel() << " parked at VIP parking lot number " << vipSpot->getParkingLotNumber() << endl;
            return;
        }
    }
    std::cout << "No VIP lot available to park the car." << std::endl;
}

void Parking::unParkCar(Car* car) {
    for (auto lot : Lots) {
        if (lot->getParkedCar() == car) {
            lot->unparkCar();
            return;
        }
    }
    std::cout << "The car is not parked in this parking." << std::endl;
}

void Parking::unParkAllCars() {
    for (auto lot : Lots) {
        if (!lot->getIsAvailable()) {
            lot->unparkCar();
        }
    }
    std::cout << "All parked cars have been removed from this parking." << std::endl;
}
