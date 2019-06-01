#include <iostream>

using namespace std;
int dp[1001];
vector<int> prime(1001);

void fib() {
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=1000; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
}

void sieve() {
    int sieve[1001]={0};
    sieve[0] = sieve[1] = -1;
    for(int i=2; i*i<n; i++){
        for(int j=2; j<i; j++){
            sieve[i*j] = -1;
        }
    }

    for(auto i: sieve){
        if(i!=-1){
            prime.push_back(i);
        }
    }
}

int main() {
	int num;
	cin >> num;
	sieve();
    fib();

    if(num%2==0){
        cout<<dp[n/2];
    }else cout<<prime[(n-1)/2];

    return 0;
}
