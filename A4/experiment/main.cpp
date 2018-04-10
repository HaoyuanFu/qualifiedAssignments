#include <iostream>
#include <cassert>

#include "Deck.h"

using namespace std;

int main() 
{
  cout << "'make experiment' will run this main" << endl;

  Deck deck;

  for (int i = 0; i < deck.NUM_P / 2; ++i) {
    assert(deck.getPileSize(i) == 7);
  }
  for (int i = deck.NUM_P / 2; i < deck.NUM_P; ++i) {
    assert(deck.getPileSize(i) == 6);
  }
  for (int i = 0; i < deck.NUM_C; ++i) {
    assert(deck.isCellEmpty(i));
  }
  for (int i = 0; i < deck.NUM_F; ++i) {
    assert(deck.isFoundationEmpty(i));
  }
  
  return 0;
}