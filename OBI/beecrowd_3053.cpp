#include <iostream>
#include <algorithm>
using namespace std;

int main() {
 
    int iter, play;
    char truth;

    cin >> iter >> truth;
    char pos[3] = {'F', 'F', 'F'};
    pos[truth - 65] = truth;

    for (int i = 0; i < iter; i++){
        cin >> play;
        if (play == 1){
            swap(pos[0], pos[1]);
        } else if (play == 2){
            swap(pos[1], pos[2]);
        } else if (play == 3){
            swap(pos[0], pos[2]);
        }
    } 

    if (pos[0] != 'F') cout << 'A' << endl;
    else if (pos[1] != 'F') cout << 'B' << endl;
    else if (pos[2] != 'F') cout << 'C' << endl;
 
    return 0;
}