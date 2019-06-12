#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void subsetGenerator(vector<vector<int> > &list, vector<int> a, vector<int> o, int i){

    if(i==a.size()){
        list.pb(o);
        o.clear();
        return;
    }

    subsetGenerator(list,a,o,i+1);
    o.pb(a[i]);
    subsetGenerator(list,a,o,i+1);
    return;

}

bool subsetSumChecker(vector<int> a){
    vector< vector<int> > list;
    vector<int> o;
    subsetGenerator(list,a, o,0);
    
    for(int i=0; i<list.size(); i++){
        if(list[i].size()!=0){
            int sum=0;
            for(auto j:list[i]) sum+=j;

            if(sum==0) return true;
        }


        // for(int j=0; j<list[i].size(); j++){
        //     cout<<list[i][j]<<" ";
        // }cout<<endl;
    }


    return false;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        vector<int> a;
        int n; cin>>n;
        for(int i=0; i<n; i++){
            int temp; cin>>temp;
            a.pb(temp);
        }

        subsetSumChecker(a)==true ? cout<<"Yes\m": cout<<"No\n";
    }
    return 0;
}