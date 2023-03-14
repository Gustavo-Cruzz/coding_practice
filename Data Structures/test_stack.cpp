#include <iostream>
#include "STACK.h"

int main() {
  stack pile;
  
  init_stack(&pile);
  push(&pile, 10);
  push(&pile, 20);
  push(&pile, 35);

  cout << "Topo = " << pile.top << endl;
  cout << "Item 1 = " << pile.data[0] << endl;
  cout << "Item 2 = " << pile.data[1] << endl;
  cout << "Item 3 = " << pile.data[2] << endl;
  
  cout << "The stack has size: " << size_stack(&pile)<< endl;

  print_stack(pile);

  return 0;
}
