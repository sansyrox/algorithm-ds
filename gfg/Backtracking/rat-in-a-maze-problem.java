// { Driver Code Starts
//Initial Template for Java

import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();

        while(t-->0){
            int n=sc.nextInt();
            int[][] a=new int[n][n];
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    a[i][j]=sc.nextInt();

            GfG g=new GfG();
            ArrayList<String> res=g.printPath(a,n);
            if(res.size()>0)
            {
                for(int i=0;i<res.size();i++)
                    System.out.print(res.get(i)+" ");
                System.out.println();
            }
            else
            {System.out.println(-1);}

        }
    }
}
// } Driver Code Ends
//User function Template for Java

// m is the given matrix and n is the order of matrix
class GfG{
    static boolean traverse(int[][] m,boolean[][] visited,int x,int y,int n,LinkedList<String> ans){
        if(m[x][y] == 0) return false;
        if(x == n-1 && y == n-1){
            ans.add("");
            return true;
        }
        boolean l = false,r = false,u = false,d = false;
        visited[x][y] = true;
        LinkedList<String> tmp = new LinkedList<>();
        if((x+1 < n )&& (visited[x+1][y] == false )&& (m[x+1][y] == 1)){
            r = traverse(m,visited,x+1,y,n,tmp);
            for(String i : tmp) ans.add("D"+i);
            tmp.clear();
        }
        if((y-1 >= 0) && (visited[x][y-1] == false) && (m[x][y-1] == 1)){
            u = traverse(m,visited,x,y-1,n,tmp);
            for(String i : tmp) ans.add("L"+i);
            tmp.clear();
        }
        if((y+1 < n) && (visited[x][y+1] == false )&&( m[x][y+1] == 1)){
            d = traverse(m,visited,x,y+1,n,tmp);
            for(String i : tmp) ans.add("R"+i);
            tmp.clear();
        }
        if((x-1 >= 0) && (visited[x-1][y] == false) && (m[x-1][y] == 1)){
            l = traverse(m,visited,x-1,y,n,tmp);
            for(String i : tmp) ans.add("U"+i);
            tmp.clear();
        }

        visited[x][y] = false;
        if(ans.size() == 0) return false;
        return true;

    }
    public static ArrayList<String> printPath(int[][] m, int n)
    {
//        Your code here
//        System.out.println("");
//        for(int[] i : m){
//            System.out.println(Arrays.toString(i));
//        }
        LinkedList<String> ll = new LinkedList<>();
        boolean[][] visited = new boolean[n][n];
        if(traverse(m,visited,0,0,n,ll)){
            return new ArrayList<>(ll);
        }else{
            return new ArrayList<>();
        }


    }
}