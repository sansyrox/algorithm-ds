class Solution {
    public int[] singleNumber(int[] nums) {
        int sum = 0;
        int[] a = new int[2];
        for(int i : nums) sum ^= i;
        sum &= -sum;
        for(int i : nums) if((i & sum) == 0){
            a[0] ^= i;
        }else{
            a[1] ^= i;
        }
        return a;
    }
}