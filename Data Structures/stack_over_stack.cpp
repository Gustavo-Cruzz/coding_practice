#include <iostream>
#include "STACK.h"

int main() {
  stack pile, pile2;
  
  
  init_stack(&pile);
  init_stack(&pile2);

  push(&pile, 1);
  push(&pile, 2);
  push(&pile, 3);
  push(&pile2, 10);
  push(&pile2, 20);

  cout << "Pile 1: \n";
  print_stack(pile);

  cout << "Pile 2: \n";
  print_stack(pile2);
  
  pile_of_stacks(&pile, pile2);

  cout << "Restacked pile 1: \n";  
  print_stack(pile);
  
}
