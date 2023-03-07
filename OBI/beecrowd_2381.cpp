#include <iostream>
#include <algorithm> 
#include <string>
#include <vector> 

using namespace std;
 
int main() {
    int n_students, gift;
    vector<string> names;
    string name;

    cin >> n_students >> gift;

    for (int i = 0; i < n_students; i++){
        cin >> name;

        names.push_back(name);
    }

    sort(names.begin(), names.end());
    cout << names[gift-1] << endl;
}
