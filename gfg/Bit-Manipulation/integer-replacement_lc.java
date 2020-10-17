class Solution {
    public int integerReplacement(long n) {
        int count = 0;
        if(n == 1) return 0;
        while(n > 1){
            count++;
            // System.out.println(Integer.toBinaryString(n)+" "+count);
            if((n&1) == 1){
                if(n > 3 &&(n&0b11) == 0b11){
                    n+=1;
                }else{
                    n-=1;
                }
            }else{
                n>>=1;
            }
        }
        return count;

    }
}