#include <iostream>
#include "STACK.h"

int main() {
  stack pile, pile2;
  int remove_odds = 0;
  int remove_evens = 1;

  init_stack(&pile);
  push(&pile, 1);
  push(&pile, 2);
  push(&pile, 3);
  push(&pile, 4);
  push(&pile, 5);

  init_stack(&pile2);
  push(&pile2, 10);
  push(&pile2, 20);
  push(&pile2, 35);

  cout << "Initial Stack" << endl;
  print_stack(pile);
  
  remove_odds_or_evens(&pile, remove_odds);
  
  cout << "Final Stack after removing odds" << endl;
  print_stack(pile);


  return 0;
}
