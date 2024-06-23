#ifndef CAR_H
#define CAR_H
#include <string>

using namespace std;

class Car {
private:
    string *car_model;
    string *car_plate;
public:
    Car();
    Car(string _car_model);
    Car(string _car_model, string _car_plate);
    ~Car();
    void showCarInfo();
    string getCarModel();
    string getCarPlate();
};

#endif
