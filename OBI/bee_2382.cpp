#include <iostream>
#include <cmath>
 
using namespace std;
 
int main() {
    int box_diagonal;
    int L, A, P, R;

    cin >> L >> A >> P >> R;
 
    // If diagonal <= diameter, it fits
    box_diagonal = sqrt(L * L + A * A  + P * P);
    if (box_diagonal <= 2 * R) cout << 'S' << endl;
    else cout << 'N' << endl; 

    return 0;
}