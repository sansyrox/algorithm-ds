#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#include <unordered_map>

class Node{

public:
    char data;
    unordered_map<char, Node*> h;
    bool isTerminal;
    
    Node(char d){
        data =d;
        isTerminal = false;
    }
};

class Trie{
    Node* root=new Node('\0');
    public:

    void addWord(string s){
        Node* temp=root;
        for(int i=0; i<s.length(); i++){
            if(temp->h[s[i]]){
                temp = temp->h[s[i]];
            }
            else {
                temp->h[s[i]]= new Node(s[i]);
            }
        }

        temp->isTerminal = true;

    }
s

    Node* lookUp(string s){
        Node* temp = root;
        
        for(int i=0; i<s.length(); i++){
            if(temp->h[s[i]]){
                temp = temp->h[s[i]];
            }
            else {
                return NULL;
            }
        }

        return temp;
    }

    void printSuggestions(Node* temp, string till_now, char level='a'){
        if(temp->isTerminal){
            cout<<till_now<<endl;
        }

        for(char i='a'; i<=level; i++){
            if(temp->h[i]){
                till_now+=to_string(i);
                printSuggestions(temp->h[i],till_now,level+1);
            }
        }
    }

};

int main() {
    Trie t;
    int n; cin>>n;
    while(n--){
        string x; cin>>x;
        t.addWord(x);
    }
    int y;
    cin>>y;

    for(int i=0; i<y; i++){
        string x; cin>>x;
        Node* temp = t.lookUp(x);
        if(temp==NULL){
            cout<<"No Suggestions"<<endl;
            continue;
        }
        else {
            t.printSuggestions(temp, x);
        }
    }



    return 0;
}