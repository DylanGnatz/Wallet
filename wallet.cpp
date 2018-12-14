#include "wallet.h"
#include <iostream>
#include <math.h>
using namespace std;

Wallet::Wallet() {
    for (unsigned int &i : _cash) {
        i = 0;
    }
}

Wallet::Wallet(unsigned int fives, unsigned int ones, unsigned int quarters,
               unsigned int dimes, unsigned int nickels, unsigned int pennies) {
    _cash[0] = fives;
    _cash[1] = ones;
    _cash[2] = quarters;
    _cash[3] = dimes;
    _cash[4] = nickels;
    _cash[5] = pennies;
    for (int i = 0; i < 5; i++){
        if (_cash[i] < 0){
            throw (string) "Invalid parameters.";
        }
    }

}

double Wallet::dollarAmount() const {
   double total = 0.0;
   for (int i = 0; i < 6; i++){
       total +=  _cash[i] * _values[i];
   }
   return total;

}

Wallet Wallet::operator+ (const Wallet &w2) {
    unsigned int fives = _cash[0] + w2._cash[0];
    unsigned int ones = _cash[1] + w2._cash[1];
    unsigned int quarters = _cash[2] + w2._cash[2];
    unsigned int dimes = _cash[3] + w2._cash[3];
    unsigned int nickels = _cash[4] + w2._cash[4];
    unsigned int pennies = _cash[5] + w2._cash[5];
    return {fives, ones, quarters, dimes, nickels, pennies};
}

double Wallet::operator+ (const double &d) {
    double total = dollarAmount();
    total += d;
    return total;
}

ostream& operator<<(ostream& o, const Wallet& wallet) {
    o << "{" << "Fives: " << wallet._cash[0];
    o << " | Ones: " << wallet._cash[1];
    o << " | Quarters: " << wallet._cash[2];
    o << " | Dimes: " << wallet._cash[3];
    o << " | Nickels: " << wallet._cash[4];
    o << " | Pennies: " << wallet._cash[5] << "}";
    return o;
}

Wallet Wallet::operator- (const double &d) {
    Wallet temp;
    unsigned int newamt, fives, ones, quarters, dimes, nickels, pennies;
    if (dollarAmount() < d) {
        throw string("Insufficient funds");
    } else {
        newamt = (unsigned int) ((dollarAmount() - d)  * 100);
        fives =  newamt / 500;
        newamt = newamt % 500;
        ones = newamt / 100;
        newamt = newamt % 100;
        quarters = newamt / 25;
        newamt = newamt % 25;
        dimes =  newamt / 10;
        newamt = newamt % 10;
        nickels =  newamt / 5;
        newamt = newamt % 5;
        pennies = newamt;

        temp = Wallet(fives, ones, quarters, dimes, nickels, pennies);
    }
    return temp;
}

double Wallet::operator[] (const int& i) {
    if (i >= 0 && i < 6) {
        return _cash[i];
    } else {
        throw string("Invalid Index");
    }
}

bool Wallet::operator== (const Wallet &op2) {
    return dollarAmount() == op2.dollarAmount();
}
