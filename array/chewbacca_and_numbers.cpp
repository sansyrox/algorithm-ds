#include<iostream>
#include<string>
using namespace std;

int main() {
    long long x; cin>>x;
    string s = to_string(x);
    // cout<<s;
    
    long long n = s.length();
    
    if(int(s[0]-'0') > 4 and s[0]!='9') {
        s[0] = '0' +  (9 - int(s[0]-'0') );
    }

    for(long long i=1; i<n; i++) {
        if(int(s[i]-'0') > 4) {
            s[i] = '0' +  (9 - int(s[i]-'0') );
        }
    }
    

    long long y = stoll(s);
    cout<<y;



    return 0;
}