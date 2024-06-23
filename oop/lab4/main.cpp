#include <iostream>
#include "Parking.h"

int main() {
    int numLots;
    int numVIPLots;

    std::cout << "Enter number of standard parking lots:" << std::endl;
    std::cin >> numLots;
    std::cout << "Enter number of VIP parking lots:" << std::endl;
    std::cin >> numVIPLots;

    Parking* parking = new Parking(numLots, numVIPLots);


    Car* car1 = new Car("Toyota", "ABC123");
    parking->parkToFreeLot(car1);
    Car* car2 = new Car("BMW", "XYZ789");
    parking->parkToVIPLot(car2);

    parking->showParkingInfo();

    system("pause");

    cout << "The end! Clerning memory..." << endl;

    delete parking;
    delete car1;
    delete car2;

    return 0;
}
