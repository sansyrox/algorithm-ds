#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define hashmap unordered_map<char, Node*>

class Node {
    public:
    char data;
    hashmap h;
    bool isTerminal;

    Node(char d){
        data = d;
        isTerminal = false;
    }

};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node('\0');
    }
    // insertion
    void addWord(char *word){
        Node* temp = root;
        for(int i=0; word[i]!='\0'; i++){
            char ch = word[i];

            if(temp->h.count(ch)==0){
                Node* child = new Node(ch);
                temp->h[ch] = child;
            }
            else {
                temp = temp->h[ch];
            }
        }
        temp->isTerminal = true;
    }


    // LookUp
    bool search(char *word){
        Node* temp =root;

        for(int i=0; word[i]!='\0'; i++){
            char ch = word[i];

            if(temp->h.count(ch)){
                temp = temp->h[ch];
            }
            else {
                return false;
            }
        }

        return temp->isTerminal;
    }
};

int main() {
    char word[10][100] = {"apple", "ape", "coder", "coding blocks", "no"};

    Trie t;
    for(int i=0; i<5; i++){
        t.addWord(word[i]);
        cout<<word[i]<<endl;
    }

    char searchWord[100];
    cin.getline(searchWord,100);

    if(t.search(searchWord)) {
        cout<<searchWord<<" found "<<endl;
    }
    else {
        cout<<"not found !"<<endl;
    }
    return 0;
}