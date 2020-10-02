/*
This code is a dynamic programming approach using c++ stl for huffman coding.
this code shows all relevant details for huffman coding problem solving
*/
#include <bits/stdc++.h>
using namespace std;
unordered_map<char,string> vse;
struct Node{
    //A node structure
  char alpha;
  unsigned freq;
  Node *left,*right;
  Node(char alpha,int freq){
      left=NULL,right=NULL;
      this->alpha = alpha;
      this->freq = freq;
  }
    
};

struct compare{
    //comparison between node frequencies
  bool operator()(Node *l,Node *r){
      return (l->freq > r->freq);
  }  
};

void print(struct Node* root,string s){
    if(!root){
        return;
    }
    if (root->alpha != '$'){
        cout << root->alpha << ": " << s << "\n";
        vse.insert(make_pair(root->alpha,s));
    }
  
    print(root->left, s + "0"); 
    print(root->right, s + "1"); 
} 
  


void huffman(vector<char> characs,vector<int> freqs){
    //declaring pointer variables of type struct
    struct Node *left,*right,*top;
    //declaring priority_queue for prioritizing freqs in queue
    priority_queue<Node*,vector<Node*>,compare> heap;
    //pushing node in priority_queue    
    for(int i=0;i<characs.size();i++){
        heap.push(new Node(characs[i],freqs[i]));
    }
    //creating huffman tree untill min heap size of priority_queue becomes 1
    while(heap.size() != 1){
        //selecting first top node as left node
        left = heap.top();
        heap.pop();
        // selecting second top node as right node
        right = heap.top();
        heap.pop();
        //creating new node '$' is symbol for parent nodes
        top = new Node('$',left->freq+right->freq);
        top->left = left;
        top->right =right;
        heap.push(top);
    }
    //calling print for printing codes
    print(heap.top(),"");
}


int main()
{
    char s[100];
    cout<<"Enter the Message : \n";
    //taking message input
    cin.getline(s,100);
    int k=0, len = strlen(s), j;
    //removing any spaces if any in message
    for( k = 0; k < strlen(s); k++) {
      if (s[k] == ' ') {
         for (j = k; j < len; j++)
            s[j] = s[j+1];
            len--;
      }
    }
    len = strlen(s);
    vector<char> characs;
    vector<int> freqs;
    //making a mapping between characters and their frequency
    unordered_map<char,int> m;
    for(int i=0;s[i];i++){
        if(m.find(s[i])==m.end()){
            m.insert(make_pair(s[i],1));
        }else{
            m[s[i]]++;
        }
    }
    //printing message
    cout<<"Message : "<<s<<"\n";
    //putting characters and frequency in separate vectors
    for(auto x:m){
        characs.push_back(x.first);
        freqs.push_back(x.second);
    }
    //variables for without encoding
    int size_we = len*8;
    //variables for fixed size encoding
    int bits_fixedsize;
    if(characs.size() >0 && characs.size()<=2){
        bits_fixedsize = 1;
    }else if(characs.size() > 2 && characs.size() <= 4){
        bits_fixedsize = 2; 
    }else if(characs.size() >4 && characs.size() <= 7){
        bits_fixedsize = 3;
    }else if(characs.size() >7 && characs.size()<=15){
        bits_fixedsize = 4;
    }else if(characs.size() >15 && characs.size()<= 25){
        bits_fixedsize = 5;
    }
    //calculation for fixed size encoding
    int message_bits = len*bits_fixedsize;
    int code_bits = bits_fixedsize*characs.size();
    int character_bits = characs.size()*8;
    
    int total = message_bits + code_bits + character_bits;
    cout<<"********************************************\n";
    cout<<"Size of the message without encoding\n";
    cout<<"SIZE = "<<size_we<<" bits"<<"\n";
    
    cout<<"********************************************\n";
    cout<<"FIXED SIZE ENCODING TOTAL BITS"<<"\n";
    cout<<"Message bits : "<<message_bits<<"\n";
    cout<<"Code Bits : "<<code_bits<<"\n";
    cout<<"Character Bits : " <<character_bits<<"\n";
    cout<<"Total : "<<total<<" bits"<<"\n";
    cout<<"********************************************\n";
    cout<<"********************************************\n";
    cout<<"***********VARIABLE SIZED CODES*************\n";
    //calling huffman function for creation fo huffman tree for variable size encoding
    huffman(characs,freqs);

    //calculation for variable size encoding
    int message_bits_vse = 0;
    for(auto x: vse){
        message_bits_vse += (x.second).length()*m.at(x.first);
    }
    int character_bits_vse = 8*characs.size();
    int code_bits_vse = 0;
    for(auto x:vse){
        code_bits_vse += (x.second).length();
    }
    int total_vse = message_bits_vse + code_bits_vse + character_bits_vse;
    cout<<"\n";
    cout<<"********************************************\n";
    cout<<"VARIABLE SIZE ENCODING TOTAL BITS"<<"\n";
    cout<<"Message bits : "<<message_bits_vse<<"\n";
    cout<<"Code Bits : "<<code_bits_vse<<"\n";
    cout<<"Character Bits : " <<character_bits_vse<<"\n";
    cout<<"Total : "<<total_vse<<"bits "<<"\n";
    cout<<"********************************************\n";
    cout<<"********************************************\n";
    //BCCABBDDAECCBBAEDDCC
    return 0;
}