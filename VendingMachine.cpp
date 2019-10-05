//
// Created by nick on 10/5/19.
//

#include "VendingMachine.h"

VendingMachine::VendingMachine() {
    this->change = false;
    this->dime = 0;
    this->nickel = 0;
    this->quarter =0;
    this->value = 0;

}

VendingMachine::VendingMachine(int n, int d, int q) {
    this->change = false;
    this->value = 0;
    this->nickel = n;
    this->dime = d;
    this->quarter =q;
}

int *VendingMachine::getChange(int val, int quarter, int dime, int nickel) {
    int* out = new int[3];
    int q = 0;
    int n = 0;
    int d = 0;
    while (q * 25 <= val - 25) {
        q++;
    }
    val -= (q * 25);
    while (d * 10 <= val - 10) {
        d++;
    }
    val -= (d * 10);
    while (n * 5 <= val - 5) {
        n++;
    }
    val -= (n * 5);

    out[0] = q;
    out[1] = d;
    out[2] = n;

    return out;
}

std::string VendingMachine::toString() {
    string s = string("Current value: " + to_string(this->value) + "\nNickels: " + to_string(this->nickel) + " Dimes: "\
    + to_string(this->dime) + " Quarters: " + to_string(this->quarter)+ " Change: " + to_string(this->change) + "\n");
    return s;
}

void VendingMachine::getInput(string input) {
    int n = 0;
    int d = 0;
    int q = 0;
    int c = 0;
    int w = 0;
    for (int i = 0; i < input.length(); i++) {
        char charAt = input[i];
        if (charAt == 'q') {
            q++;
        } else if (charAt == 'd') {
            d++;
        } else if (charAt == 'n') {
            n++;
        } else if (charAt == 'c') {
            c++;
        } else if (charAt == 'w') {
            w++;
        }
    }
    this->lambda();
    this->delta(n, d, q, c, w);

}

void VendingMachine::lambda() {
    int val = this->value;
    while (val >= 100) {
        //vend coffee
        cout <<"Coffee" << endl;
        val -= 100;
    }
    if (this->change) {
        int* changeBack = this->getChange(val,this->quarter,this->dime,this->nickel);
        int q = changeBack[0];
        int d = changeBack[1];
        int n = changeBack[2];
        string change = "Here is your change:";
        if (q > 0) {
            change += " " + to_string(q) + " quarters";
        }
        if (d > 0) {
            change += " " + to_string(d) + " dimes";
        }
        if (n > 0) {
            change += " " + to_string(n) + " nickels";
        }
        cout << change << endl;
        delete[](changeBack);
    }
}


void VendingMachine::delta(int n, int d, int q, int c, int w) {
    // The vending machine must check to see these conditions before it adjusts value
    // React to lambda conditions
    while (this->value >= 100) {
        //vend as many coffees as it can
        this->value -= 100;
    }
    if (this->change) {
        int * changeBack = this->getChange(this->value,this->quarter,this->dime,this->nickel);
        int quarter = changeBack[0];
        int dime = changeBack[1];
        int nickel = changeBack[2];

        this->value = 0;
        this->quarter -= quarter;
        this->nickel -= nickel;
        this->dime -= dime;
        // We want the change flag to reset after every time the user gets change
        this->change = false;
        delete[](changeBack);
    }

    // Then adjust state based on input
    int totalN = n * 5;
    int totalD = d * 10;
    int totalQ = q * 25;
    if (c > 0) {
        this->change = true;
    }
    this->nickel += n;
    this->dime += d;
    this->quarter += q;
    this->value += totalD + totalN + totalQ;
}
