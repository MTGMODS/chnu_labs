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
    Car(const Car &other);
    Car(Car &&other);
    Car& operator=(const Car& other);
    ~Car();

    void showCarInfo() const;
    string getCarModel() const;
    string getCarPlate() const;

    friend std::ostream& operator<<(std::ostream& out, const Car& car);
    friend std::istream& operator>>(std::istream& in, Car& car);

};

#endif
