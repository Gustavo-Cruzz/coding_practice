#include <iostream>
#include <algorithm> 
#include <vector> 

using namespace std;
 
int main() {

    int num, last_num, sum, n_cases;

    cin >> n_cases;
    cin >> num;
    
    last_num = num;
    sum = num;

    // for (int i = 1; i < n_cases; i++){
    //     cin >> num;
    //     sum += (num - last_num >= 10) ? 10: num-last_num;
    //     cout << "sum: " << sum << endl;
    //     cout << endl;

    //     last_num = num;
    // }
    // sum += 10;

    cout << sum << endl;
}