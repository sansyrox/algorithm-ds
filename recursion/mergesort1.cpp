#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
#define pb push_back

// ll N;

void merge( int A[], int s,int mid, int e, int n){
    int c[100];


    int i=s,j=mid+1;
    int k=s;
    while(i<=mid and j<=e){
        if(A[i]<A[j]){
            c[k++] = A[i++];
        } else {
            c[k++] = A[j++];
        }
    }

    while(i<=mid){
        c[k++] = A[i++];
    }

    while(j<=e){
        c[k++] = A[j++];
    }


    for(int x=s; x<=e; x++){
        A[i]=c[i];
        
    }

}

void mergeSort(int A[], int s, int e, int n){
    
    if(s>=e){
        return;
    }

    int mid = (s+e)/2;
    mergeSort(A,s,mid,n);
    mergeSort(A,mid+1,e,n);

    merge(A,s,mid,e,n);


}

int main(){
    
    int N;
    cin>>N;
    int A[N];

    for(int i=0 ;i <N; i++){
        cin>>A[i];
    }

    

    mergeSort(A,0,N-1,N);

    for(int i=0 ;i<N; i++){
        cout<<A[i]<<" ";
    }
    

    return 0;
}