// noah tola nat2eh 11/25/19
#include "binary_heap.h"
#include "huffmannode.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

void encode(huffmannode* x, string result, string arr[]);

int main(int argc, char **argv){
  if(!( argc == 2)){
    cout<< "supply input file name only"<<endl;
    exit(1);
  }
   
  
 FILE *f = fopen(argv[1], "r");
   if (f==NULL) {
     cout << "file doesnt  exist"<<endl;
     exit(2);
   }
   float let= 0.0;
   string codeArray[127];
   int aValue; 
   char e;
   string none= "";
   int array[127];
   for(int i=0;i<127;i++){
     array[i]=0;
   }
   while ((e=fgetc(f)) != EOF){
     aValue = (int) e;
     if (aValue >31 && aValue<127){
       let++;
       array[aValue]++;
     }
   }
   binary_heap* hp = new binary_heap();
   for(int i = 0; i<127; i++){
     if(array[i] !=0){
       int frequency = array[i];
       char character = char (i);
       hp->insert(new huffmannode(character, frequency));
     }}
   while( hp->size()> 1){
     huffmannode* tmp1 = hp ->deleteMin();
     huffmannode* tmp2 = hp -> deleteMin();
     int Dummyvalue = tmp1->frequency + tmp2->frequency;
     hp-> insert(new huffmannode(Dummyvalue,tmp1,tmp2));
   }
   encode(hp->findMin(), none, codeArray);
   cout<< " ----------------------------------"<<endl;
   rewind(f);
   float uB = let*8;
   float cB = 0;

   while ((e=fgetc(f)) != EOF){
     cB = cB + codeArray[int(e)].size();
     cout<<codeArray[int(e)]<<"";
     }
   cout << endl;
   cout<<"-----------------------------------"<<endl;
   cout<<"Compression ratio: "<< uB/cB<<endl;
   cout<< "the cost of the Huffman tree is " <<cB/let<< " bits per character" << endl;
   fclose(f);
   return 0;
}

void encode(huffmannode* x, string result, string arr[]){
  int val = x->character;
  if (x->right !=NULL){
    encode(x->right, result+"1",arr);}
  if (x->left !=NULL){
    encode(x->left, result+"0", arr);}
  if ((x->right == NULL) && (x->left == NULL)) {
      arr[val]= result;
      if (char(val) == ' ') {
	cout << "space" << " " <<result<<endl;
      }
      else{
	cout<< char(val)<< " " << result << endl;
      }}
    
}
     
		    
   
       
	 
     
