#include <iostream> 
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> read_data(){
    // Loads data from 03_rucksacks.txt
    vector<string> rucksacks;
    fstream file("data/03_rucksacks.txt");
    string line;

    if (file.is_open()){
        for (int line_num = 1; getline(file, line) && line != "\n"; line_num++){
            rucksacks.push_back(line);
        }
    }

    return rucksacks;
}

int value_of_chars(char &duplicant){
    int score = (int) duplicant;

    if (score > 91){
        score = score -96;
    } else{
        score = score -38;
    }
    return score;
}

int get_duplicates(string &line){
    // Finds a commom char for both halfs string
    int half = line.length() / 2;
    for (int i = 0; i < half; i++){
     for (int j = half; j < line.length(); j++){
            if (line[i] == line[j]){
                return value_of_chars((line)[j]);
            }
        }
    }
    return 0;
}

int find_triplets(string a, string b, string c) {
    // Finds a common letter among 3 strings

    for (int k = 0; k < a.length(); k++){
        if (b.find(a[k]) != string::npos && c.find(a[k]) != string::npos){
                return value_of_chars(a[k]);                
        }
    }
    return 0;
}

int main() {
    vector<string>::iterator txt_line;
    vector<string> rucksacks = read_data();
    
    int sum_doubles = 0;
    int sum_triples = 0;

    for (txt_line = rucksacks.begin(); txt_line < rucksacks.end(); ++txt_line){
        sum_doubles += get_duplicates(*txt_line);      
    }

    for (int i = 0; i <= rucksacks.size() - 1; i+=3){
        // Computes in sets of three
        sum_triples += find_triplets(rucksacks[i], rucksacks[i+1], rucksacks[i+2]);
    }

    // Find the item type that appears in both compartments of each rucksack. 
    // What is the sum of the priorities of those item types?
    cout << "The sum of duplicant items is: " << sum_doubles << endl;

    // Find the item type that corresponds to the badges of each three-Elf group. 
    // What is the sum of the priorities of those item types?
    cout << "The sum of lines (in sets of 3) with equal items is: " << sum_triples << endl;

    return 1;
}