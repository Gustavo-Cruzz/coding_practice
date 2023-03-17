#include <iostream>
 
using namespace std;
 
int main() {
 
    int count = 0;
    const int EYE_FOTONS = 40000000;
    int telescope, n_stars, star_fotons;

    cin >> telescope;
    cin >> n_stars;

    for (int i = 0; i < n_stars; i++){
        cin >> star_fotons ;
        if (star_fotons * telescope >= EYE_FOTONS) count += 1;
    }
    cout << count << endl;
 
    return 0;
}