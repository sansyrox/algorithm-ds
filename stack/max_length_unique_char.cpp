#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int maxLenUniqueChar(string s){
    int helper[256] ={0};
    deque<char> q;

    int max1=0,temp_max=0;
    for(auto j:s){

        if(helper[int(j)]==0){
            q.push_back(j);
            helper[j]++;
            temp_max++;
        }
        else {
            max1=max(max1,temp_max);
            while(!q.empty() and q.front()!=j){
                helper[q.front()]--;
                q.pop_front();
            }
            if(q.front()==j) q.pop_front();
            q.push_back(j);
            temp_max=q.size();
        }
    }

    return max(max1,temp_max);

}

int main() {
    string s;
    cin>>s;
    cout<<maxLenUniqueChar(s);       
    return 0;
}