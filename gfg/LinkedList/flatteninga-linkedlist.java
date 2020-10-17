// { Driver Code Starts
import java.util.Scanner;
import java.util.*;
import java.io.*;

class Node
{
    int data;
    Node next;
    Node bottom;

    Node(int d)
    {
        data = d;
        next = null;
        bottom = null;
    }
}


class Flatttening_A_LinkedList
{
    Node head;

    void printList(Node node)
    {
        //Node temp = head;
        while (node != null)
        {
            System.out.print(node.data + " ");
            node =node.bottom;
        }
        System.out.println();
    }
    public  static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        Flatttening_A_LinkedList list = new Flatttening_A_LinkedList();
        while(t>0)
        {
            int N = sc.nextInt();
            int arr[] = new int[N];
            for(int i=0;i<N;i++)
                arr[i] = sc.nextInt();

            Node temp = null;
            Node tempB = null;
            Node pre = null;
            Node preB = null;
            int flag=1;
            int flag1=1;
            for(int i=0; i<N;i++)
            {
                int m = arr[i];
                m--;
                int a1 = sc.nextInt();
                temp = new Node(a1);
                if(flag == 1)
                {
                    list.head = temp;
                    pre = temp;
                    flag = 0;
                    flag1 = 1;
                }
                else
                {
                    pre.next = temp;
                    pre = temp;
                    flag1 = 1;
                }

                for(int j=0;j<m;j++)
                {
                    int a = sc.nextInt();
                    tempB = new Node(a);
                    if(flag1 == 1)
                    {
                        temp.bottom = tempB;
                        preB = tempB;
                        flag1 = 0;
                    }
                    else
                    {
                        preB.bottom = tempB;
                        preB = tempB;
                    }
                }

            }
            //list.printList();
            GfG g = new GfG();
            Node root = g.flatten(list.head);
            list.printList(root);

            t--;
        }
    }
}// } Driver Code Ends
/*Node class  used in the program
class Node
{
	int data;
	Node next;
	Node bottom;

	Node(int d)
	{
		data = d;
		next = null;
		bottom = null;
	}
}
*/
/*  Function which returns the  root of
    the flattened linked list. */
class GfG
{
    Node method1(Node root){
        Node temp = root;
        Node flat = null,bflat = null;
        int len = 0;
        while(temp != null) {
            len++;
            temp = temp.next;
        }
        Node[] index = new Node[len];
        temp = root;
        for(int i = 0;i<len;i++){
            index[i] = temp;
            temp = temp.next;
        }
        int min_i = 0;
        Node min = index[0];
        int nv = 0;
        boolean br = true;
        while(br){
            nv = 0;
            for(int i = 0;i<len;i++){
                if(index[i] == null && i == len-1) {
                    br = false;
                    break;
                }
                if(index[i] != null){
                    min = index[i];
                    min_i = i;
                    break;
                }
            }
            if(br == false) break;
            for(int i = min_i+1;i<len;i++){
                if(index[i] != null){
                    if(min.data >= index[i].data){
                        min = index[i];
                        min_i = i;
                    }else{
                        break;
                    }
                }else{
                    nv++;
                }
            }

            if(bflat != null){
                flat.bottom = min;
//                System.out.println(nv);

                flat = min;
                index[min_i] = min.bottom;
            }else{
                flat = bflat = min;
                index[min_i] = min.bottom;
            }
        }
        return bflat;

    }
    Node method2(Node root){
        Node flat = null,bflat = null;
        Node a = root;
        Node b = root.next;
        root = root.next;
        do{
            // System.out.println(a+" "+b);
            if(root != null){ root = root.next;}
            while(a != null && b != null) {
                // System.out.println("#");
                if (a.data < b.data) {
                    if (bflat == null) {
                        bflat = flat = a;
                        a = a.bottom;
                    }else{
                        flat.bottom = a;
                        flat = a;
                        a = a.bottom;
                    }
                } else{
                    if (bflat == null) {
                        bflat = flat = b;
                        b = b.bottom;
                    }else{
                        flat.bottom = b;
                        flat = b;
                        b = b.bottom;
                    }
                }
            }
            if(b != null){
                while(b != null){
                    flat.bottom = b;
                    flat = b;
                    b = b.bottom;
                }
            }
            if(a != null){
                while(a != null){
                    // System.out.println(flat);
                    if(bflat == null){
                        bflat = flat = a;
                        // flat = a;
                        a = a.bottom;
                        continue;
                    }
                    flat.bottom = a;
                    flat = a;
                    a = a.bottom;
                }
            }
            a = bflat;
            b = root;
            flat = bflat = null;
//            root = root.next;
        }while(root != null);
        return a;
    }
    Node flatten(Node root)
    {
        // Your code here
        return method2(root);

    }
}