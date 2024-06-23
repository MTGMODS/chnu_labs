#ifndef PARKING_H
#define PARKING_H

#include <vector>
#include "Car.h"

class ParkingLot {
private:
    int* lotNumber;
    bool* isAvailable;
    Car* parkedCar;
public:
    ParkingLot(int _lot_number);
    ParkingLot(int _lot_number, bool _available, Car* car = nullptr);
    ~ParkingLot();

    int getParkingLotNumber();
    bool getIsAvailable();
    void showParkingLotInfo();
    void parkCar(Car* car);
    void unparkCar();
    Car* getParkedCar();
};

class Parking {
private:
    int maxParkingSpots;
    std::vector<ParkingLot*> spots;
public:
    Parking();
    Parking(int _maxParkingSpots);
    ~Parking();

    void showParkingInfo();
    ParkingLot* getParkingLot(int lotNumber);

    void parkToFreeLot(Car* car);
    void parkToLotNumber(int lotNumber, Car* car);
    void unParkCar(Car* car);
    void unParkAllCars();
};

#endif
