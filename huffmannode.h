// noah tola nat2eh 11/25/19
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

class huffmannode{
 public:
  huffmannode();
  huffmannode(char x, int y);
  huffmannode(int x, huffmannode* l, huffmannode* r);
  char character;
  huffmannode* right;
  huffmannode* left;
  int frequency;

 private:
  friend class huffmanenc;
};
#endif
