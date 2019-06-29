int Solution::removeElement(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    auto i=A.begin(), e=A.end();
    
    auto pend = std::remove(i,e,B);
    
    A.resize(std::distance(i,pend));
    i=A.begin();
    
    int count=0;
    for(;i!=pend; i++){
        count++;
    }
    
    
    
    return count;
}
