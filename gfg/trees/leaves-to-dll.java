// { Driver Code Starts
//Initial Template for Java

import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;

class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}

class Main {

    static Node buildTree(String str){

        if(str.length()==0 || str.charAt(0)=='N'){
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while(queue.size()>0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if(!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if(i >= ip.length)
                break;

            currVal = ip[i];

            // If the right child is not null
            if(!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }
    static void printInorder(Node root)
    {
        if(root == null)
            return;

        printInorder(root.left);
        System.out.print(root.data+" ");

        printInorder(root.right);
    }

    public static void main (String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t=Integer.parseInt(br.readLine());

        while(t-- > 0){
            String s = br.readLine();
            Node root = buildTree(s);
            Tree g = new Tree();
            Node head_ref = null;
            Node head = g.convertToDLL(root);
            printInorder(root);
            System.out.println();
            Node temp = head;
            Node last = null;
            while(temp!=null){
                last = temp;
                System.out.print(temp.data+" ");
                temp = temp.right;
            }
            System.out.println();
            temp = last;

            while(temp!=null){
                System.out.print(temp.data+" ");
                temp = temp.left;
            }
            System.out.println();


        }
    }
}


// } Driver Code Ends


//User function Template for Java

class Tree{
    // return the head of the DLL and remove those node from the tree as well.
    static Node head = null;
    static Node prev = null;
    static Node inorder(Node root){
        if(root == null) return null;
        if(root.left == null && root.right == null){
            if(head == null){
                head = root;
                prev = root;
                return null;
            }else{
                root.left = prev;
                prev.right = root;
                prev = root;
                return null;
            }
        }
        root.left = inorder(root.left);
        root.right = inorder(root.right);
        return root;
    }
    public Node convertToDLL(Node root)
    {
        // Code here
        head = prev = null;
        inorder(root);
        return head;
    }

}

