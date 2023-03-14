#ifndef STACK.H 
#define STACK.H
#include <iostream>
using namespace std;
#define size 100

typedef int new_member;

typedef struct stack{
  int top;
  new_member data[size];
};

void init_stack(stack *pilha){
  pilha->top = -1;  
}


int is_hollow(stack *pilha) {
  if(pilha->top == -1){
    cout << "\n";
    return 1;
  }
  return 0;
}


int is_full(stack *pilha) {
  if (pilha->top == size -1) {
    cout << "The stack is full.\n";
    return 1;
  }
  return 0;
}


void add_top(stack *pilha){
  pilha->top++;
} 


void rm_top(stack *pilha){
  pilha->top--;
} 


void push(stack *pilha, new_member item){
  
  if (is_full(pilha)) 
      return 0;
  
  add_top(pilha);
  pilha->data[pilha->top] = item;
  
  return 1;
}


void pop(stack *pilha, new_member *item){
  if (is_hollow(pilha)) return 0;

  // Remove o item do top e decrementa o top
  *item = pilha->data[pilha->top];
  rm_top(pilha);
  return 1;
}


int return_top(stack *pilha, new_member *item){
  if(is_hollow(pilha)) return 0;

  *item = pilha->data[pilha->top];
  return 1;
}


int size_of_stack(stack *pilha){
  return pilha->top + 1;
}


void print_stack(stack pilha){
    new_member removed;
  
    while(is_hollow(&pilha) != 1){
      pop(&pilha, &removed);
      cout << "Item " << pilha.top + 1 << " = " << removed << endl;
  }
}


void clear_stack(stack *pile){
  new_member removed;
  int current_top = pile->top;
  for (int i = 0; i <= current_top; i++){
    pop(pile, &removed);
  }
}


int compare_stacks(stack pile1, stack pile2){  
  if(pile1.top != pile2.top){
    cout << "The stacks are different!\n\n";
    return 1;
  }

  int top = pile1.top;
  int value1, value2;
  
  for (int i = 0; i <= top; i++){
    pop(&pile1, &value1);
    pop(&pile2, &value2);

    if (value1 != value2){
      cout << "The stacks are different!\n\n";
      return 1;
    }
  }

  cout << "They are the same!\n\n";

  return 0;  
}

void pile_of_stacks(stack *pile, stack pile2){
  // Stacks the second stack over the first
  new_member item, items[size];
  for (int i = 0; i <= pile->top; i++){
    pop(&pile2, &item);
    items[i] = item;    
  }

  for (int i = pile->top-1; i  >= 0; i--){
    push(pile, items[i]);    
  }
}

void remove_odds_or_evens(stack *pile, int remainder){
  // remainder must be either 0 for evens or 1 for odds
  if (remainder != 0 && remainder != 1) {
    cout << "Remainder must be 0 zero evens or 1 for odds!" << endl;
    cout << "Remainder changed to 0; Removing Odds\n";
    remainder = 0;
  }
  
  stack even_pile;
  int removed, current_top;

  init_stack(&even_pile);

  // When poping the stacks, their top is decreased
  // So we need to track the top before poping
  current_top = pile->top;
  for (int i = 0; i <= current_top; i++){
    // The original pile becomes empty
    pop(pile, &removed);
    
    // Saves all evens, but in reverse order    
    if(removed % 2 == remainder) {
        push(&even_pile, removed);
    }
  }
  
  current_top = even_pile.top;
  for (int i = 0; i <= current_top; i++){
    // Pushes all evens so that they are in the original order
    pop(&even_pile, &removed);
    push(pile, removed);
  }

}

#endif
