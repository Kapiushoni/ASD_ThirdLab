#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Iphone {
    long long serialNumber;
    string color;
    bool hasCharger;

    Iphone() {
        serialNumber = rand() % 10000000;
        string colors[] = {"Black", "White", "Blue", "Natural Titanium"};
        color = colors[rand() % 4];
        hasCharger = rand() % 2;
    }
};

using Data = Iphone;


struct HashNode {
    long long key;
    Data value;
};