#include <iostream>
 
using namespace std;
 
int main() {
    // Tier of cost per water usage 
    int tier_1 = 7; // Fixed price 0 - 10m³
    int tier_2 = 1; // 11 - 30 m³
    int tier_3 = 2; // 31 - 100 m³
    int tier_4 = 5; // 101 - 120 m³

    int usage;
    int total_price = tier_1;
    cin >> usage;

    if (usage >= 101) {
        total_price += tier_4 * (usage -100) + 140 + 20;
    } else if (usage >= 31){
        total_price += tier_3 * (usage -30) + 20;
    } else if (usage >= 11) {
        total_price += tier_2 * (usage -10);
    }
    
    cout << total_price << endl;
    return 0;
}