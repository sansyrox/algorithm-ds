#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Queries{  

    stack<int> cost;

    public:
    int Student(){
        if(!cost.empty()){
            int x = cost.top();
            cost.pop();
            return x;
        }

        return -1;
    }

    void instructor(int d){
        
        cost.push(d);
    }


};


int main() {
    // string abc;
    // getline(cin,abc);
    // cout<<abc
    
    int q; cin>>q;
    Queries x;
    while(q--){
        // cout<<"ek";
        
        int a,b;
        cin>>a;
        // cin>>a;
        // cout<<a;
        if(a==1){
            x.Student()!=-1?cout<<x.Student()<<endl:cout<<"No Code\n";
        }
        else{
            cin>>b;
            cout<<a << " "<<b;
            x.instructor(b);
        }
    }
    return 0;
}