import java.util.*;
class Main{
    static int dfs(Map<Integer,Integer> map,Set<Integer> vis,int src){
        vis.add(src);
        if(!vis.contains(map.get(src))){
            return dfs(map,vis,map.get(src))+1;
        }
        return 1;
    }
    public static int minSwaps(int[] A, int N)
    {//add code here.
/*        int count = 0;
        for(int i = 0;i<N;i++){
            int indx = i;
            int val = A[i];
            for(int j = i;j<N;j++){
                if(A[indx] > A[j]) indx = j;
            }
            if(indx != i){
                int temp = A[indx];
                A[indx] = A[i];
                A[i] = temp;
                count++;
            }
        }
        return count;

 */
   int[] temp = A.clone();
   Map<Integer,Integer> map = new HashMap<>();
   Set<Integer> vis = new HashSet<>();
   Arrays.sort(temp);
   int count = 0;
   for(int i = 0;i<N;i++) map.put(temp[i],A[i]);
   for(int i : temp){
       if(!vis.contains(i) && map.get(i) != i){
           count+=(dfs(map,vis,i)-1);
       }
       vis.add(i);
   }
   return count;
    }
    public static void main(String[] arg){
        int[] arr = new int[]{7,6,3,2};
        System.out.println(minSwaps(arr,arr.length));
    }
}