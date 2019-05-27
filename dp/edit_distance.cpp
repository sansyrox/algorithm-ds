#include<iostream>
using namespace std;

int editDistance(string a, string b, int i){

    if (a[i]==a[b]) {
        i++;
    }
    


}


int main(){

    string a="emial",b="email";
    cout<<editDistance(a,b);

    return 0;
}