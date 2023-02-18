#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/* For this task we will rearrange some boxes that look like this:

                    [L] [M]         [M]    
                [D] [R] [Z]         [C] [L]
                [C] [S] [T] [G]     [V] [M]
        [R]     [L] [Q] [B] [B]     [D] [F]
        [H] [B] [G] [D] [Q] [Z]     [T] [J]
        [M] [J] [H] [M] [P] [S] [V] [L] [N]
        [P] [C] [N] [T] [S] [F] [R] [G] [Q]
        [Z] [P] [S] [F] [F] [T] [N] [P] [W]

Into something else based on text inputs */

using row = vector<string>;
using matrix = vector<vector<char>>;

row get_data(const string& filename) {
    row data;
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        // Read each line and add it to the vector
        while (getline(file, line)) {
            if (line.empty()) continue;

            data.push_back(line);
        }
        file.close();
    }
    return data;
}

matrix load_crates(row data){
    int array_index = 0;
    int row_with_crates = 8;
    matrix crates = {{}, {}, {}, {}, {}, {}, {}, {}, {}};

    for (int i = 0; i < row_with_crates; i++){
        for (int j = 1; j <= data[i].size(); j+=4) {
            if (data[i][j] != ' '){
                array_index = (int) j / 4;
                crates[array_index].push_back(data[i][j]);
            }
        }
    }
    return crates;
}

vector<int> load_coordinates(row data){
    vector<int> commands;
    string word;
    
    for(int i=9; i < data.size(); i++){
        istringstream iss(data[i]);

        while (iss >> word){            
            if (isdigit(word[0])) {
                commands.push_back(stoi(word));
            }; 
        }
    }
    return commands;
}

int rearrange_crates(matrix crates, vector<int> coord, bool inverse=false){

    int amount, origin, target;

    for (int i = 0; i < coord.size() -2; i += 3){
        // -1 is used due to array indexes statrting at 0
        amount = coord[i];
        origin = coord[i+1] -1;
        target = coord[i+2] -1;

        // Loads correspond crates and inverts the array if necessary
        vector<char> moving_crates(crates[origin].begin(), crates[origin].begin() + amount);
        if (inverse == true) reverse(moving_crates.begin(), moving_crates.end());

        for (int j = 0; j < moving_crates.size(); j++){           
            // Appends crates to their new array
            crates[target].insert(crates[target].begin(),  moving_crates[j]);

            // Removes crates from orginal array
            crates[origin].erase(crates[origin].begin());
        }
    }
    // Prints the final arrangement from crates
    for (int k = 0; k < crates.size(); k++){
    for (int l = 0; l < crates[k].size(); l++){
                cout << crates[k][l] << ' ';
        }cout << endl;
    }
    cout << endl;
    return 0;
}

int main() {
    row data = get_data("data/05_giant_cargo_crane.txt");
    matrix crates = load_crates(data);
    vector<int> coordinates = load_coordinates(data);

    rearrange_crates(crates, coordinates);
    cout << "INVERTING "<< endl;
    rearrange_crates(crates, coordinates, true);

    return 0;
}