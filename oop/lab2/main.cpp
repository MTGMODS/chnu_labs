#include <iostream>
#include "Parking.h"
#include "Car.h"

int main() {
    Parking* parking = new Parking(3);

    Car* car1 = new Car("Lamborgini SVJ", "CE-1331-EC");
    Car* car2 = new Car("Honda", "AA-7777-BB");

    parking->parkToFreeLot(car1);
    parking->parkToFreeLot(car2);

    parking->showParkingInfo();

    return 0;
}
