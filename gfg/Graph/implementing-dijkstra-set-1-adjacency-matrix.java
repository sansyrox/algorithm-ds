// { Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.next());

        while(t > 0)
        {
            int V = Integer.parseInt(sc.next());;
            ArrayList<ArrayList<Integer>> list = new ArrayList<>(V);
            for(int i = 0;i < V; i++)
            {
                ArrayList<Integer> temp = new ArrayList<>(V);
                list.add(i, temp);
            }

            for(int i = 0; i < V; i++)
            {
                ArrayList<Integer> temp = list.get(i);
                for(int j = 0; j < V; j++)
                {
                    temp.add(Integer.parseInt(sc.next()));
                }
                list.add(temp);
            }
            int s = Integer.parseInt(sc.next());;
            Solution T = new Solution();
            T.dijkstra(list, s, V);
            System.out.println();
            t--;
        }
    }
}// } Driver Code Ends
//User function Template for Java

// Function to implement Djikstra
// list: adjacency list representing the graph
// src: source vertex to start traversal
// V: number of vertices

class Solution
{
    static void dijkstra(ArrayList<ArrayList<Integer>> list, int src, int V)
    {
        // Write your code here
        PriorityQueue<int[]> queue = new PriorityQueue<>(new Comparator<int[]>(){
            public int compare(int[] a,int[] b){
                return a[1]-b[1];
            }
        });
        Set<Integer> set = new HashSet<>();
        int[] dist = new int[V];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[src] = 0;     //{index,distance}
        queue.add(new int[]{src,0});
        while(!queue.isEmpty()){
            int[] t1 = queue.poll();
            if(set.contains(t1)){
                continue;
            }
            set.add(t1[0]);
            for (int i = 0; i < V; i++) {
                if(i != t1[0] &&
                        list.get(t1[0]).get(i) != 0 &&
                        !set.contains(i) &&
                        list.get(t1[0]).get(i) + t1[1] < dist[i]){
                    dist[i] = list.get(t1[0]).get(i) + t1[1];
                    queue.add(new int[]{i,dist[i]});
                }
            }
        }
        for (int i : dist) System.out.print(i+" ");
    }
}
