#include <iostream>
 
using namespace std;
 
int main() {
 
    int side, width;
    int type1, type2;
    cin >> side >> width;

    type1 = (side * width) + (width-1) * (side - 1);
    type2 = (side-1) * 2 + (width-1) * 2;
    cout << type1 << endl;
    cout << type2 << endl; 
    return 0;
}