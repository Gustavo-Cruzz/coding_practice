#include <iostream>

using namespace std;
 
int main() {
 
    int value, payment, remain, fixed;
    cin >> value >> payment;

    remain = value % payment;
    fixed = (value - remain) / payment;

    for (int i = 0; i < remain; i++){
        cout << fixed + 1 << endl;
    }

    for (int i = remain; i < payment; i ++){
        cout << fixed << endl;
    }
 
    return 0;
}