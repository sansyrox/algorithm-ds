#include<bits/stdc++.h>
#include<ctime>
#include<cstdlib>
using namespace std;

void shuffle(int *a, int s, int e){

    srand(time(NULL));

    int i,j,temp;

    for(int i=e; i>0; i--){
        j=rand()%i+1;
        swap(a[i],a[j]);
    }


}


int partition(int *a, int s, int e){
    int i=s-1;
    int j= s;
    int pivot = a[e];
    for(;j<e; j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }

    swap(a[i+1],a[e]);
    return i+1;

}

void quickSort(int *a, int s, int e){
    if(s>=e){
        return;
    }

    int p = partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort( a,p+1,e);

}

int main(){

    int arr[]={2,1,4,6,7,5,8};
    int n = sizeof(arr)/sizeof(int);
    shuffle(arr,0,n-1);
    quickSort(arr,0,n-1);

    // srand(time(NULL));
    // cout<<"The no is"<<rand() %100<<endl;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}