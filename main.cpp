#include <iostream>
#include "wallet.h"
using namespace std;

int main() {
    Wallet w1;
    Wallet w2(1,2,3,4,5,6);

    cout << "w1 " << w1 << ", w2 " << w2 << endl;

    cout << "\nDemo dollar amounts -- should be 0 and 8.46" << endl;
    cout << w1 << " " << w1.dollarAmount() << endl;
    cout << w2 << " " << w2.dollarAmount() << endl;

    cout << "\nAdding w1 and w2" << endl;
    cout << (w1 + w2) << endl;

    cout << "\nAdding w2 and w2" << endl;
    cout << (w2 + w2) << endl;

    cout << "\nAdding a constant -- should be a 18.46" << endl;
    cout << (w2 + 10.0) << endl;

    cout << "\nSubtract .06 from w2 -- should subtract a nickle and penny, result is 8.40" << endl;
    Wallet sub = w2 -.06;
    cout << "  " << sub << " " << sub.dollarAmount();

    cout << "\nSubtract 7.30 from w2 result should be 1.16" << endl;
    Wallet sub2 = w2 - 7.30;
    cout << "  " << sub2 << " " << sub2.dollarAmount() << endl;

    cout << "\nAccess array elements of w2 one by one " << endl;
    for (int i=0; i < 6; i++ ) {
        cout << w2[i] << "  ";
    }
    cout << endl;


    Wallet w3(0, 1, 3, 2, 0, 0);  //1.95
    Wallet w4(0, 0, 2, 10, 5, 20); // 1.95
    cout << "Test equality with " << w3 << " and " << w4 << endl;
    cout << "\nw3 and w4 should be equal" << endl;
    cout << w3.dollarAmount() << " " << w4.dollarAmount() << endl;
    cout << (w3 == w4) << endl;
    cout << "\nw2 and w4 should not be equal" << endl;
    cout << w2.dollarAmount() << " " << w4.dollarAmount() << endl;
    cout << (w2 == w4) << endl;
}
