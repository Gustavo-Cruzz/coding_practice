#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <map>       // std::map
#include <fstream>   // read file
#include <string>

using namespace std;

int play(char rival_play, char my_play, map<char, int> all_scores){
    // Calculates scores for each round of rock, paper scissors

    int my_score = all_scores.find(my_play)->second;
    int rival_score = all_scores.find(rival_play)->second;

    if (my_score == rival_score){
        my_score += 3;
    } else if (my_score < rival_score and rival_score - my_score == 2) {
        my_score += 6;
    } else if (my_score > rival_score and my_score - rival_score != 2){
        my_score += 6;
    }

    return my_score;
};

int main()
{
    int final_score = 0;
    int second_challenge_score = 0;

    vector<string> play_guide;
    string line;

    map<char, int> scores;

    scores['X'] = 1;
    scores['Y'] = 2;
    scores['Z'] = 3;
    scores['A'] = 1;
    scores['B'] = 2;
    scores['C'] = 3;

    ifstream file("data/02_encryption.txt");
    if (file.is_open())
    {
        for (int line_num = 1; getline(file, line) && line != "\n"; line_num++)
        {
            play_guide.push_back(line);
        }
    }

    // Removes the \n at the end on the vector
    play_guide.pop_back();
    vector<string>::iterator iter;

    // Iterate over characters and send them to "play" function
    for (iter = play_guide.begin(); iter < play_guide.end(); iter++){
        final_score += play((*iter)[0], (*iter)[2], scores);
    }

    cout << "My final score for Rock Paper Scissors is: " << final_score << endl;
}