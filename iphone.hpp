#ifndef IPHONE_H
#define IPHONE_H

#include <string>
using namespace std;

class Iphone {
public:
    string serialNumber;
    string name;
    string color;
    string model;

    Iphone(string sn, string n, string c, string m)
        : serialNumber(sn), name(n), color(c), model(m) {}

    // Comparison operators
    bool operator<(const Iphone& other) const {
        return serialNumber < other.serialNumber;
    }

    bool operator>(const Iphone& other) const {
        return serialNumber > other.serialNumber;
    }

    bool operator==(const Iphone& other) const {
        return serialNumber == other.serialNumber;
    }
};

#endif // IPHONE_H
