#include <iostream>
#include "Parking.h"
#include "Car.h"

int main() {

    int numLots;
    cout << "Enter number of parking lots:" << endl;
    cin >> numLots;
    Parking* parking = new Parking(numLots);

    system("pause");

    Car* car1 = new Car("Lamborgini SVJ", "CE-1331-EC");
    Car* car2 = new Car("Lada Vesta", "AA-7777-BB");
    parking->parkToFreeLot(car1);
    parking->parkToFreeLot(car2);

    system("pause");

    const Car car3("Volga", "CE-1111-XM");
    // const Car car3
    cout << "Show const car info" << endl;
    car3.showCarInfo();
    // cout << "Delete const car" << endl;
    // delete &car3;

    system("pause");
    cin.ignore();
    cout << "Created new car..." << endl;
    Car car4;
    cin >> car4;
    cout << "Print car info:" << endl;
    cout << car4;
    cout << "parking this car to free parking lot:" << endl;
    parking->parkToFreeLot(&car4);

    system("pause");
    cout << "Show Parking information..." << endl;
    parking->showParkingInfo();
    cout << "Total parking lots: " << parking->getTotalParkingLots() << endl;

    system("pause");
    cout << "The end, clearning memory..." << endl << endl;
    delete parking;
    delete car1;
    delete car2;
    delete &car4;

    return 0;
}