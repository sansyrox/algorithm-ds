#include<bits/stdc++.h>
using namespace std;

int returnMinCost(int ai[],int bi[], int n, int m, int c1, int c2, int c3 ,int c4) {
    
    // c1 ke liye 
    int no_of_rides = 0;
    for(int i=0; i<n; i++) no_of_rides+=ai[i];
    for(int i=0; i<m; i++) no_of_rides+=bi[i];


    // c2 ke liye 
    int no_of_distinct = 0;
    for(int i=0; i<n; i++) {
        if(ai[i]!=0) no_of_distinct++;
    }
    for(int i=0; i<m; i++) {
        if(bi[i]!=0) no_of_distinct++;
    }


    // c3 ke liye
    int cab_or_rick = 0;
    for(int i=0; i<n; i++) {
        if(ai[i]!=0) {
            cab_or_rick +=1; 
            break;
        }
    }
    for(int i=0; i<m; i++) {
        if(bi[i]!=0) {
            cab_or_rick +=1; 
            break;
        }
    }


    return min(

        min(no_of_rides*c1,no_of_distinct*c2),
        min(c4,cab_or_rick*c3)

    );

}


int main() {

    int c1,c2,c3,c4;
    int n,m;
    cin>>c1>>c2>>c3>>c4;
    cin>>n>>m;
    int ai[n];

    for(int i=0; i<n; i++) cin>>ai[i];

    
    int bi[m];
    for(int j=0; j<m; j++) cin>>bi[m];


    cout<<returnMinCost(ai,bi,n,m,c1,c2,c3,c4);
    return 0;
}