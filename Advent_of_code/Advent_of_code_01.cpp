#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <fstream>   // read file
#include <string>

using namespace std;

int main()
{
    vector<string> calories;
    vector<int> sum_of_calories;
    vector<string>::iterator iter;

    int vec_size;
    int total = 0;
    int sum_top_3 = 0;
    int largest_calory = 0;

    string line; // Reads a single line from the file

    // Open file and append data to the vector
    ifstream file("data/01_elf_calories.txt");
    if (file.is_open())
    {
        for (int line_num = 1; getline(file, line) && line != "\n"; line_num++)
        {
            calories.push_back(line);
        }
    }

    for (iter = calories.begin(); iter < calories.end(); iter++)
    {

        if (*iter != "")
        {                         // Avoids sum of empty spaces or "\n"
            total += stoi(*iter); // Sums as integer "77" -> int 77
        }
        else
        {
            if (total > largest_calory)
            {
                largest_calory = total;
            }
            sum_of_calories.push_back(total);
            total = 0;
        }
    }

    sort(sum_of_calories.begin(), sum_of_calories.end());

    vec_size = sum_of_calories.size() - 1; // -1 is necessary to use .at() and access allocated memory

    cout << "The elf carring most calories has: " << largest_calory << " calories" << endl;
    cout << "The sum of the 3 elfs carrying the most calories is: " << sum_of_calories.at(vec_size) + sum_of_calories.at(vec_size - 1) + sum_of_calories.at(vec_size - 2) << endl;
}