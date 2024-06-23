#ifndef PARKING_H
#define PARKING_H

#include <vector>
#include <iostream>
#include "Car.h"

class ParkingLot {
protected:
    int* lotNumber;
    bool* isAvailable;
    Car* parkedCar;

public:
    ParkingLot(int _lot_number);
    ParkingLot(int _lot_number, bool _available, Car* car = nullptr);
    ~ParkingLot();

    ParkingLot(const ParkingLot& other);
    ParkingLot(ParkingLot&& other);
    ParkingLot& operator=(const ParkingLot& other);

    int getParkingLotNumber();
    bool getIsAvailable();
    void showParkingLotInfo();
    void parkCar(Car* car);
    void unparkCar();
    Car* getParkedCar();
};

class ParkingVIPLot : public ParkingLot {
public:
    ParkingVIPLot(int _lot_number);
    ParkingVIPLot(int _lot_number, bool _available, Car* car = nullptr);
    ~ParkingVIPLot();

    ParkingVIPLot(const ParkingVIPLot& other);
    ParkingVIPLot(ParkingVIPLot&& other);
    ParkingVIPLot& operator=(const ParkingVIPLot& other);

    void showParkingLotInfo();
};

class Parking {
private:
    static int totalParkingLots;
    int maxParkingLots;
    int maxVIPParkingLots;
    std::vector<ParkingLot*> Lots;

public:
    Parking();
    Parking(int _maxParkingLots, int _maxVIPParkingLots);
    ~Parking();

    Parking(const Parking& other);
    Parking(Parking&& other);
    Parking& operator=(const Parking& other);

    void showParkingInfo();
    ParkingLot* getParkingLot(int lotNumber);

    void parkToFreeLot(Car* car);
    void parkToLotNumber(int lotNumber, Car* car);
    void parkToVIPLot(Car* car);
    void unParkCar(Car* car);
    void unParkAllCars();

    static int getTotalParkingLots();
};

#endif
