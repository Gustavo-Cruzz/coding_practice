#include <iostream>
#include <string>

using namespace std;
 
int main() {
    string text;
    int counter;

    while(getline(cin, text)){
        counter = 0;
        for(int i = 0; i < text.size(); i++){
          if (text[i] == '(') counter++;
          if (text[i] == ')') counter--;
          if (counter < 0) counter -= 100;
        }
      if (counter != 0) cout << "incorrect\n";
      else cout << "correct\n";
    }
    return 0;
}