#include <iostream>
using namespace std;

bool lenCheck(string s){
    int i=0;
    for(;i<s.length(); i++){
        if(s[i]>='0'and s[i]<='9'){
            break;
        }
    }
    
    int len_of_word = i;
    string number="";
    for(;i<s.length(); i++){
        number.push_back(s[i]);
    }
    
    if(len_of_word==0){
        if(number==""){
            return true;
        }
        if(stoi(number)==0){
            return true;
        }
        
        return false;
    }
    
    return to_string(len_of_word)==number;
}

int main() {
	//code
	int t; cin>>t;
	while(t--){
	    string s;cin>>s;
	    cout<<lenCheck(s);
	}
	return 0;
}