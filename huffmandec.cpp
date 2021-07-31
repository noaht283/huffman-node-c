// Noah Tola nat2eh 11/26/19 
#include "huffmannode.h"
#include "binary_heap.h"
#include <string>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

void buildtree(huffmannode* b, string pref, char ch);
void decode(huffmannode* a, string s , huffmannode* rt);


int main (int argc, char **argv) {
  huffmannode* root= new huffmannode(' ', 0);
  if (argc >  2) {
    exit(1);
  }
  ifstream file(argv[1], ifstream::binary);
  if (! file.is_open()) {
    exit(2);
  }
  
  while(true){
    string character, prefix;
    file >> character;
    if( (character[0] == '-') && (character.length() > 1))
      break;
    if (character == "space")
      character= " ";
    file >> prefix;
    cout << "character "<< character << " has prefix code: "<< prefix << endl;
    buildtree(root, prefix, character[0]);
  }

  stringstream ss;

  while (true) {
    string bt;
    file >> bt;

    if (bt[0] == '-')
      break;

    ss << bt;
  }

  string abit= ss.str();

  cout<< abit << endl;
  decode(root,abit,root);
  cout<<endl;

  file.close();
}
 void decode (huffmannode* a, string s, huffmannode* rt) {
   if ((a->left == NULL) && (a->right == NULL)) {
     cout << a->character;
     decode(rt, s, rt);
   }
   else {
      if (s[0] == '1') {
       decode(a->right, s.substr(1, s.length()-1), rt);
     }
     
      else if (s[0] == '0') {
       decode(a->left, s.substr(1,s.length()-1),rt);
     }}}
     
    
	
    
void buildtree(huffmannode* b, string pref, char ch) {
  if(pref.length() <1){
     b ->character= ch;
    b->right = NULL;
    b->left = NULL; 
  }
  if (pref[0] == '1') {
    if (b->right!= NULL){
      buildtree(b->right,pref.substr(1,pref.length()-1),ch);
      }
    else {
      b->right = new huffmannode(' ',0);
      buildtree(b->right,pref.substr(1,pref.length()-1),ch);
		}}	
  if (pref[0] == '0') {
    if (b->left != NULL){
      buildtree(b->left, pref.substr(1,pref.length()-1),ch);
    }
    else {
      b-> left = new huffmannode(' ',0);
      buildtree(b->left, pref.substr(1,pref.length()-1),ch);
    }}}


		
