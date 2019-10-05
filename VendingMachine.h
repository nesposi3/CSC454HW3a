//
// Created by nick on 10/5/19.
//

#ifndef CSC454HW3A_VENDINGMACHINE_H
#define CSC454HW3A_VENDINGMACHINE_H

#include <iostream>
#include <sstream>
using namespace std;
class VendingMachine {
private:
    int nickel;
    int dime;
    bool change;
    int value;
    int quarter;
    int* getChange(int val,int quarter,int dime, int nickel);
public:
    VendingMachine();
    VendingMachine(int n, int d, int q);
    string toString();
    void getInput(string input);

    void lambda();

    void delta(int i, int i1, int i2, int i3, int i4);
};


#endif //CSC454HW3A_VENDINGMACHINE_H
