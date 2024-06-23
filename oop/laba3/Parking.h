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

    ParkingLot(const ParkingLot &other);
    ParkingLot(ParkingLot &&other);

    int getParkingLotNumber();
    bool getIsAvailable();
    void showParkingLotInfo();
    void parkCar(Car* car);
    void unparkCar();
    Car* getParkedCar();
};

class Parking {
private:
    static int totalParkingLots;
    int maxParkingLots;
    std::vector<ParkingLot*> Lots;
public:
    Parking();
    Parking(int _maxParkingLots);
    ~Parking();

    Parking(const Parking &other);
    Parking(Parking &&other);

    void showParkingInfo();
    ParkingLot* getParkingLot(int lotNumber);

    void parkToFreeLot(Car* car);
    void parkToLotNumber(int lotNumber, Car* car);
    void unParkCar(Car* car);
    void unParkAllCars();

    static int getTotalParkingLots();

};

#endif