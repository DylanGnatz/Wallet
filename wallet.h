#ifndef WALLET_H_
#define WALLET_H_
#include <iostream>
using namespace std;

class Wallet {
private:

    unsigned int _cash[6];
    double _values[6] = {5.0, 1.0, 0.25, 0.10, 0.05, 0.01};
    int removeCash(int, double);
    double round(double);

public:
    Wallet();
    Wallet(unsigned int, unsigned int, unsigned int,
           unsigned int, unsigned int, unsigned int);
    double dollarAmount() const;
    friend ostream& operator<<(ostream&, const Wallet&);
    Wallet operator+(const Wallet&);
    double operator+(const double&);
    Wallet operator-(const double&);
    double operator[] ( const int&);
    bool operator== (const Wallet&);
};




#endif /* WALLET_H_ */
