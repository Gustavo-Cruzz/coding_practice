#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <map>       // std::map
#include <fstream>   // read file
#include <string>

using namespace std;

int play_second_challenge(char rival_play, char my_play, map<char, int> all_scores)
{
    // The elfs have changed the game! And we will adapt to win!

    int my_score = 0;
    int match_score = all_scores.find(my_play)->second;
    int rival_score = all_scores.find(rival_play)->second;

    if (my_play == 'X')
    {
        my_score += rival_score - 1;
    }
    else if (my_play == 'Y')
    {
        my_score += rival_score;
    }
    else if (my_play == 'Z')
    {
        my_score += rival_score + 1;
    }

    if (my_score > 3)
    {
        my_score = 1;
    }
    else if (my_score < 1)
    {
        my_score = 3;
    }

    return my_score + match_score;
};

int main()
{
    int final_score = 0;
    int second_challenge_score = 0;

    vector<string> play_guide;
    string line;

    map<char, int> scores;

    scores['X'] = 0;
    scores['Y'] = 3;
    scores['Z'] = 6;
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
    for (iter = play_guide.begin(); iter < play_guide.end(); iter++)
    {
        second_challenge_score += play_second_challenge((*iter)[0], (*iter)[2], scores);
    }

    cout << "On the second challenge I got:: " << second_challenge_score << endl;
}