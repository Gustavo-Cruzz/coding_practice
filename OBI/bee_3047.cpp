#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
 
    int age_M, age1, age2, age3, age_max;
    cin >> age_M >> age1 >> age2;

    age3 = age_M - (age1 + age2);

    age_max = max(age1, age2);
    age_max = max(age_max, age3);
    
    cout << age_max << endl;
 
    return 0;
}