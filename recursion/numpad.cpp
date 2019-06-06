#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

// char keypad[][10] = {
//     "",
//     "",
//     "ABC",
//     "DEF",
//     "GHI",
//     "JKL",
//     "MNO",
//     "PQRS",
//     "TUV",
//     "WXYZ"
// };

void generateStrings(map<char,string> keypad,string num, int i=0, string output="") {
    // cout<<"Idahar"<<endl;
    if(i==num.length()){
        // cout<<"Idahar"<<endl;
        cout<<output<<endl;
        return;
    }

// cout<<typeid(num[i]).name()<<endl;

    string s = keypad[num[i]];
    // cout<<s;
    if(s.length()==0){
        output[i]=' ';
        // 0 and 1 ke case main 0 ya one hi aane do kyuki texting mai aisa hotas
        generateStrings(keypad,num,i+1,output);
    }
    for(int j=0; j<s.length(); j++){
        output[i]=s[j];
        generateStrings(keypad,num,i+1,output);
    }


}

int main() {
    map<char,string> keypad;
    keypad['0']="";
    keypad['1']="";
    keypad['2']="ABC";
    keypad['3']="DEF";
    keypad['4']="GHI";
    keypad['5']="JKL";
    keypad['6']="MNO";
    keypad['7']="PQRS";
    keypad['8']="TUV";
    keypad['9']="WXYZ";

    string num;
    cin>>num;

    generateStrings(keypad,num,0,num);
        
    return 0;
}