#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int number(string a, int i){

    if(i==a.size()-1){
        return (int)((a[i]-'0')*1);
    }

    return (int)((a[i]-'0')*pow(10, a.size()-i-1)) + number(a,i+1) ;



}

int main() {
    string a;
    cin>>a;
    
    cout<<number(a,0);

    return 0;
}