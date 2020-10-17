// { Driver Code Starts
import java.util.*;
import java.lang.*;

class Pair
{
    int x;
    int y;

    public Pair(int a, int b)
    {
        x = a;
        y = b;
    }
}

class Chainlength
{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0)
        {
            int n = sc.nextInt();
            Pair pr[] = new Pair[n];
            int arr[] = new int[2*n];
            for(int i = 0; i < 2*n; i++)
            {
                arr[i] = sc.nextInt();
            }
            for(int i = 0, j = 0; i < 2*n-1 && j < n; i = i+2, j++)
            {
                pr[j] = new Pair(arr[i], arr[i+1]);
            }
            GfG g = new GfG();
            System.out.println(g.maxChainLength(pr, n));
        }
    }
}
// } Driver Code Ends

class CompareByFirst implements Comparator<Pair>
{
    public int compare(Pair a, Pair b)
    {
        // return a.x - b.x;
        return a.y - b.y;
    }
}

class GfG
{
    int maxChainLength(Pair arr[], int n)
    {
        // your code here
        Arrays.sort(arr,new CompareByFirst());
        //   int dp[] = new int[n]; // DP soln (O(n^2))
        //   Arrays.fill(dp,1);
        //   for(int i = n-1;i>=0;i--){
        //       int max = 1;
        //       for(int j = i;j<n;j++){
        //           if(arr[i].y < arr[j].x) max = Math.max(max,dp[j]+1);
        //       }
        //       dp[i] = max;
        //   }
        //     int max = 0;
        //     for(int i : dp) max = Math.max(max,i);
        int count = 1;  // greedy soln (O(nlogn))
        int end = 0;
        for(int i = 1;i<n;i++){
            if(arr[i].x > arr[end].y){
                count++;
                end = i;
            }
        }
        // return max;
        return count;
    }
}