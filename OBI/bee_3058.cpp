#include <iostream>
#include <iomanip>
using namespace std;
 
int main() {
    int cases, weight;
    double price, total;
    double smallest = 100000;

    cin >> cases;

    for (int i = 0; i < cases; i++){
        cin >> price >> weight;
        total = (price * 1000) / weight;
        if (total < smallest) smallest = total;
    }
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << smallest << endl;
 
    return 0;
}
