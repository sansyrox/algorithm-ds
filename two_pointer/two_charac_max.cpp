int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more de2 
     
    int i=2, k=2;
    int n = A.size();
    if(n<=2){
        return n;
    }
    // A[0] 
    for(i=2;i<n;){
        
        
        while(A[i]==A[k-1] and A[i]==A[k-2] and i<n){
            i++;
        }
        if(i==n-1){
            // cout<<"Idahr";
        }
        // if(A[i]!=A[k-1] and A[i]!=A[k-2])
        if(i<n)
            A[k++] = A[i++];
        // if(k)
    }

    return k;
}
