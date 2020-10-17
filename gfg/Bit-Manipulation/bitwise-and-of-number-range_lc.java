class Solution {
    public int rangeBitwiseAnd(int n, int m) {
        // int result = 0;  // method 1
        // for(int i = 30;i>=0;i--){
        //     if(((n>>i)&1) == 1 && ((m>>i)&1) == 1){
        //         result |= 1<<i;
        //     }else if(((n>>i)&1) != ((m>>i)&1)){
        //         break;
        //     }
        // }
        // return result;

        while(n < m)  //method 2
        {
            m -= (m & -m);
        }
        return m;
    }
}