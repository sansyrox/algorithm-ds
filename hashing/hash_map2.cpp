#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Fruit{
    public:
        string name;
        int price;
        string city;
    public:
        Fruit (){

        }
        Fruit(string n, int p, string c){
            name = n;
            price = p;
            city = c;
        }

};

// bool findCycle(Node* head){
//     Node* temp = head;

//     unordered_map<Node*,bool> m;

//     while(temp!=NULL){
//         if(m[temp]==true){
//             cout<<"Cycle Found";
//             return true;
//         }
//         m[temp] = true;
//         temp=temp->next;
//     }
//     return false;
// }

int main() {
    unordered_map<string,Fruit> myMap;
    Fruit f("Mango",100,"Delhi");

    myMap[f.name] = f;


    Fruit fs = myMap["Mango"];
    cout<<fs.city<<endl;

    // count function 0 or 1
    cout<<"Apple "<<myMap.count("Apple")<<endl;
    cout<<"Mango" <<myMap.count("Mango")<<endl;

    myMap.erase("Mango");

    return 0;
}