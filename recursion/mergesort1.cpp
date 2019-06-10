#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
#define pb push_back

ll N;

void merge( ll *A, ll s,ll mid, ll e){
    ll c[N];


    ll i=s,j=mid+1;
    ll k=s;
    while(i<=mid and j<=e){
        if(A[i]<A[j]){
            c[k++] = A[i++];
        }
        else c[k++] = A[j++];

    }

    while(i<=mid){
        c[k++] = A[i++];
    }

    while(j<=e){
        c[k++] = A[j++];
    }


    for(ll x=s; x<=e; x++){
        A[i]=c[i];
    }

}

void mergeSort(ll A[], ll s, ll e){
    ll mid = (s+e)/2;
    if(s>=e){
        return;
    }

    mergeSort(A,s,mid);
    mergeSort(A,mid+1,e);

    merge(A,s,mid,e);


}

int main(){
    
    
    cin>>N;
    ll A[N];

    for(ll i=0 ;i <N; i++){
        cin>>A[i];
    }

    

    mergeSort(A,0,N-1);

    for(int i=0 ;i<N; i++){
        cout<<A[i]<<" ";
    }
    

    return 0;
}