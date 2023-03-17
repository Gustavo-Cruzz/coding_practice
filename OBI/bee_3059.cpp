#include <iostream>
 
using namespace std;
 
int main() {
 
    int cases, min, max, sum, counter = 0;
    cin >> cases >> min >> max;

    int data[cases];

    for (int i = 0; i < cases; i++){
        cin >> data[i];
    }

    for (int i = 0; i < cases; i++){
        for (int j = i +1; j < cases; j++){
            sum = data[i] + data[j];
            if (i != j && sum >= min && sum <= max) counter += 1;
        }
    }
    cout << counter << endl;
    return 0;
}