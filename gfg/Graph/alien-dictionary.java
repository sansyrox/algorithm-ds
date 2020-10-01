// { Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.next());
        while(t-- > 0)
        {
            int n = Integer.parseInt(sc.next());
            int k = Integer.parseInt(sc.next());

            String[] words = new String[n];

            for(int i=0;i<n;i++)
            {
                words[i] = sc.next();
            }

            Solution T = new Solution();
            //  System.out.println(T.printOrder(words,k));
            String order = T.printOrder(words,k);

            String temp[] = new String[n];
            for(int i=0;i<n;i++)
                temp[i] = words[i];

            Arrays.sort(temp, new Comparator<String>(){

                @Override
                public int compare(String a, String b) {
                    int index1 = 0;
                    int index2 = 0;
                    for(int i = 0; i < Math.min(a.length(), b.length())
                            && index1 == index2; i++) {
                        index1 = order.indexOf(a.charAt(i));
                        index2 = order.indexOf(b.charAt(i));
                    }

                    if(index1 == index2 && a.length() != b.length())
                    {
                        if(a.length() < b.length())
                            return 1;
                        else
                            return 0;
                    }

                    if(index1 < index2)
                        return 1;
                    else
                        return 0;

                }
            });

            int flag = 1;
            for(int i=0;i<n;i++)
            {
                if(!words[i].equals(temp[i]))
                {
                    flag = 0;
                    break;
                }
            }

            System.out.println(flag);
        }
    }

}
// } Driver Code Ends
//User function Template for Java

class Graph {
    LinkedHashMap<Character,Graph> map;
    Graph(){
        map = new LinkedHashMap<>();
    }
}

class Solution
{
    static void traverse(Graph head,Queue<char[]> queue){
        char prev = '!';
        for (char i : head.map.keySet()){
            if(prev != '!'){
                queue.add(new char[]{prev,i});
            }
            prev = i;
        }
        for (char i : head.map.keySet()){
            traverse(head.map.get(i),queue);
        }
    }
    public String printOrder(String [] words,int k)
    {
        // Write your code here
        Graph head = new Graph();
        for(String i : words){
            char[] chr = i.toCharArray();
            Graph tmp = head;
            for(char j : chr){
                tmp.map.putIfAbsent(j,new Graph());
                tmp = tmp.map.get(j);
            }
        }
        Queue<char[]> queue = new LinkedList<>();
        traverse(head,queue);
//        for (char[] i : queue) System.out.println(Arrays.toString(i));
//        Set<Character> set = new HashSet<>();
//        LinkedList
        int[] result = new int[27];
        Arrays.fill(result,-1);
        char[] st = queue.peek();
        while(!queue.isEmpty()){
            char[] tmp = queue.poll();
            result[tmp[0]-'a'] = tmp[1] - 'a';
        }
        int c = st[0] - 'a';
        StringBuilder out = new StringBuilder();
        while(c > 0){
            out.append(('a'+c));
            c = result[c];
        }

    return out.toString();
    }
}