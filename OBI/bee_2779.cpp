#include <iostream>
#include <vector> 

using namespace std;
 
int main() {
 
    int missing_figs, package_length, fig;
    bool duplicate;
    vector<int> new_figs;

    cin >> missing_figs;
    cin >> package_length;
    
    for (int i = 0; i < package_length; i++){
        cin >> fig;
        duplicate = false;
        new_figs.push_back(fig);

        for (int j = 0; j < new_figs.size() -1; j++){
            if (fig == new_figs[j]) duplicate = true;
        }

        if (duplicate == false) missing_figs -= 1;
    }

    cout << missing_figs << endl;
    return 0;
}