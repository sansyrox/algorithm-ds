// { Driver Code Starts
// INITIAL CODE
import java.util.Scanner;
import java.lang.*;
import java.io.*;
import java.util.*;
import java.lang.Integer;
import java.util.HashMap;

// A Binary Search Tree node
class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
class Check_BST
{
    // driver function to test the above functions
    public static void main(String args[])
    {
        // Input the number of test cases you want to run
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        Check_BST ob = new Check_BST();
        while (t > 0)
        {
            HashMap<Integer, Node> m = new HashMap<Integer, Node> ();
            int n = sc.nextInt();


            Node root = null;

            while (n > 0)
            {
                int n1 = sc.nextInt();
                int n2 = sc.nextInt();
                char lr = sc.next().charAt(0);

                //  cout << n1 << " " << n2 << " " << (char)lr << endl;
                Node parent = m.get(n1);
                if (parent == null)
                {
                    parent = new Node(n1);
                    m.put(n1, parent);
                    if (root == null)
                        root = parent;
                }

                Node child = new Node(n2);
                if (lr == 'L')
                    parent.left = child;
                else
                    parent.right = child;
                m.put(n2, child);
                n--;
            }

            GfG g = new GfG();
            System.out.println(g.isBST(root));
            //ob.printInorder(root);
            t--;

        }
    }
}


// } Driver Code Ends
/*  A Binary Search Tree node
class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
} */
class GfG
{
    static int checkBST(Node root, int min,int max){
        if(root == null) return 1;
        if(root.data >= min && root.data <= max){
            return checkBST(root.left,min,root.data-1)*checkBST(root.right,root.data+1,max);
        }else{
            return 0;
        }
    }
    static int isBST(Node root)
    {
        return checkBST(root,Integer.MIN_VALUE,Integer.MAX_VALUE);
    }
}

