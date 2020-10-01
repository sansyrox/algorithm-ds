// { Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

class Node
{
    int data;
    Node left, right;

    public Node(int d)
    {
        data = d;
        left = right = null;
    }
}

class Main
{
    static Node buildTree(String str)
    {
        // Corner Case
        if(str.length() == 0 || str.equals('N'))
            return null;
        String[] s = str.split(" ");

        Node root = new Node(Integer.parseInt(s[0]));
        Queue <Node> q = new LinkedList<Node>();
        q.add(root);

        // Starting from the second element
        int i = 1;
        while(!q.isEmpty() && i < s.length)
        {
            // Get and remove the front of the queue
            Node currNode = q.remove();

            // Get the curr node's value from the string
            String currVal = s[i];

            // If the left child is not null
            if(!currVal.equals("N"))
            {

                // Create the left child for the curr node
                currNode.left = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                q.add(currNode.left);
            }

            // For the right child
            i++;
            if(i >= s.length)
                break;
            currVal = s[i];

            // If the right child is not null
            if(!currVal.equals("N"))
            {

                // Create the right child for the curr node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                q.add(currNode.right);
            }

            i++;
        }

        return root;
    }

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t>0)
        {
            String s = br.readLine();
            Node root1 = buildTree(s);

            s = br.readLine();
            Node root2 = buildTree(s);

            Solution T = new Solution();
            List<Integer> ans = T.merge(root1,root2);
            for(int i=0;i<ans.size();i++)
                System.out.print(ans.get(i) + " ");
            System.out.println();

            t--;
        }
    }
}
// } Driver Code Ends


//User function Template for Java

// class Node
// {
//     int data;
//     Node left, right;

//     public Node(int d)
//     {
//         data = d;
//         left = right = null;
//     }
// }

class Solution{
    // Return a integer of integers having all the nodes in both the BSTs in a sorted order.
    public List<Integer> merge(Node root1,Node root2)
    {
        // Write your code here
        Stack<Node> s1 = new Stack<>();
        Stack<Node> s2 = new Stack<>();
        List<Integer> out = new LinkedList<>();
        s1.push(root1);
        s2.push(root2);
        while(!s1.isEmpty() || !s2.isEmpty()){
            System.out.println(s1.size()+" "+s2.size());
            while(!s1.isEmpty() && s1.peek().left != null) s1.push(s1.peek().left);
            while(!s1.isEmpty() && s2.peek().left != null) s2.push(s2.peek().left);
            if(s1.isEmpty()){
                out.add(s2.peek().data);
                Node temp = s2.pop();
                if(temp.right != null) s2.push(temp.right);
                continue;
            }
//            if(s2.isEmpty()){
//                out.add(s1.peek().data);
//                Node temp = s1.pop();
//                if(temp.right != null) s1.push(temp.right);
//                continue;
//            }
//            if(s1.peek().data < s2.peek().data){
//                System.out.println("Q");
//                out.add(s1.peek().data);
//                Node temp = s1.pop();
//                if(temp.right != null) s1.push(temp.right);
//            }else{
//                System.out.println("W"+s2.peek().data);
//                out.add(s2.peek().data);
//                Node temp = s2.pop();
//                if(temp.right != null) s2.push(temp.right);
//            }

        }
        return out;
    }
}
