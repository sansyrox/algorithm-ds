class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        int n = nums.length;
        List<List<Integer>> result = new LinkedList<>();
        for(int i = 0;i<Math.pow(2,n);i++){
            List<Integer> ll = new LinkedList<>();
            int x = i,count = 0;
            while(x != 0){
                if((x&1) == 1) ll.add(nums[count]);
                count++;
                x>>=1;
            }
            result.add(ll);
        }
        return result;
    }
}