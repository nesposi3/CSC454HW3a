//
// Created by nick on 10/5/19.
//
#include "VendingMachine.h"
using namespace std;
int main(){
    int n,q,d;
    cout<< "Enter initial number of quarters, dimes and nickels" << endl;
    cin >> q >> n >>d;
    VendingMachine* vendingMachine = new VendingMachine(n,d,q);
    string command;
    while(true){
        cout <<vendingMachine->toString();
        cin >> command;
        if(command=="exit"){
            break;
        }else{
            vendingMachine->getInput(command);
        }
    }
    delete(vendingMachine);
}
