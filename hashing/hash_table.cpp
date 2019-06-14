#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#include<unordered_map>

int main() {
    unordered_map<string, int> mymap;

    mymap["Mango"] = 100;
    mymap.insert(mp("Apple",200));
    pair<string,int> p("Orange", 300);
    mymap.insert(p);


    for(pair<string,int> i:mymap){
        cout<<i.first<<" "<<i.second<<endl;
    }

    for(int i=0; i<mymap.bucket_count(); i++){
        cout<<"Bucket "<<i<<"->";
        for(auto it=mymap.begin(i); it!=mymap.end(i); it++){
            // it is a pointer to a pairs
            cout<<it->first<<","<<it->second;
        }
        cout<<endl;
    }


    return 0;
}