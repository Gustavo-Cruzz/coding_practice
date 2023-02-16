#include <iostream> 
#include <fstream>
#include <vector>

using namespace std;

vector<int> text_to_int(string input){
    string str = "";
    vector<int> intervals;

    for (int i = 0; i < input.length(); i++){
        if (input[i] != '-' && input[i] != '\n'){
            str += input[i];
        } else {
            intervals.push_back(stoi(str));
            str = "";
        }
    }    
    intervals.push_back(stoi(str));

    return intervals;
}

vector<int> get_data() {
    vector<int> data;
    string line;
    fstream file("data/04_id_cleaning.txt");

    if (file.is_open())
    {
        for (int line_num = 1; getline(file, line, ',') && line != "\n"; line_num++)
        {
            vector<int> intervals = text_to_int(line);
            // cout << "line= " << line << " endl" << endl;
            for (int i = 0; i < intervals.size(); i++) {
                data.push_back(intervals[i]);
            }
        }
    }
    return data;
}

int fully_contains(int low_l, int high_l, int low_r, int high_r){
    /* Groups data and checks whether a set fully contains another one.
       The variable names indicate which set they belong to, where low_l 
       represents the lowest number on the left set, and so on */

    int counter = 0;
    if (low_l == low_r || high_l == high_r) counter += 1;

    else if (low_l < low_r){
        if (high_l >= high_r) counter += 1;
    } 
    else if (low_l > low_r){
        if (high_l <= high_r) counter += 1;
    }

    return counter;
}

int overlaps(int low_l, int high_l, int low_r, int high_r){
    /* Checks if any of the sets overlap with the other. 
       The variable names follow the structure in "fully_contains" */
    int counter = 0;

    if (low_l == low_r || high_l == high_r) counter += 1;

    else if (low_l < low_r){
        if (high_l >= low_r) counter += 1;
    } 
    else if (low_l > low_r){
        if (low_l <= high_r) counter += 1;
    }

    return counter;
}

int main() {
    vector<int> ids = get_data();
    int fully_contained = 0;
    int overlapping = 0;

    for (int i = 0; i < ids.size(); i+=4){
        fully_contained += fully_contains(ids[i], ids[i+1], ids[i+2], ids[i+3]);
        overlapping += overlaps(ids[i], ids[i+1], ids[i+2], ids[i+3]);
    }

    cout << fully_contained << " pairs fully contain another" << endl;
    cout << overlapping << " pairs overlap" << endl;

    return 1;
}