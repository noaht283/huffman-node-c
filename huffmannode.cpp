//noah tola nat2eh 11/25/19
#include "huffmannode.h"
#include <cstddef>
#include "binary_heap.h"
huffmannode::huffmannode() {
  character = ' ';
  frequency = 0;
  left = NULL;
  right = NULL;
}
huffmannode:: huffmannode(char x, int y) {
  character =x;
  frequency=y;
  left = NULL;
  right=NULL;
}

huffmannode:: huffmannode(int x, huffmannode* a, huffmannode* b){
  character= ' ';
  frequency=x;
  left=a;
  right=b;
}
