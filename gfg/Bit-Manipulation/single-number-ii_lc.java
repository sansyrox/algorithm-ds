class Solution {
    public int singleNumber(int[] nums) {
        int a = 0,b = 0;
        for(int i : nums){
            b = b|(a&i);
            a = a^i;
            int c = ~(a&b);
            a &= c;
            b &= c;
        }
        return a;
    }
}