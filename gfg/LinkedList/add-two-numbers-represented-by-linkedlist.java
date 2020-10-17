// { Driver Code Starts
import java.util.*;
class Node {
    int data;
    Node next;

    Node() {}
    Node(int d) {
        data = d;
        next = null;
    }
}
class Add_LinkedList {
    Node head;

    void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        // System.out.println("");
    }

    public void push(int new_data) {
        /* 1 & 2: Allocate the Node &
                  Put in the data*/
        Node new_node = new Node(new_data);

        /* 3. Make next of new Node as head */
        new_node.next = head;

        /* 4. Move the head to point to new Node */
        head = new_node;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T > 0) {
            int n1 = sc.nextInt();
            Add_LinkedList list1 = new Add_LinkedList();
            for (int i = 1; i <= n1; i++) {
                int a = sc.nextInt();
                list1.push(a);
            }
            int n2 = sc.nextInt();
            Add_LinkedList list2 = new Add_LinkedList();
            for (int i = 0; i < n2; i++) {
                int b = sc.nextInt();
                list2.push(b);
            }
            Add_LinkedList list3 = new Add_LinkedList();
            Add g = new Add();
            Node rs = g.addTwoLists(list1.head, list2.head);
            list3.printList(rs);
            System.out.println();
            T--;
        }
    }
}// } Driver Code Ends
/*The Node is defined as
class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
        Node(){}
    }
*/

class Add {

    // This function will add the numbers represented by two linked lists
    Node addTwoLists(Node first, Node second) {
        // Your code here
        int carry = 0;
        int s = 0;
        Node sum = new Node(0);
        Node bsum = sum;
        while(first != null && second != null){
            s = first.data+second.data;
            sum.next = new Node((s+carry)%10);
            carry = (s+carry)/10;
            sum = sum.next;
            first = first.next;
            second = second.next;
        }
        if(first != null){
            while(first != null){
                s = first.data;
                sum.next = new Node((s+carry)%10);
                carry = (s+carry)/10;
                sum = sum.next;
                first = first.next;
            }
        }else if(second != null){
            while(second != null){
                s = second.data;
                sum.next = new Node((s+carry)%10);
                carry = (s+carry)/10;
                sum = sum.next;
                second = second.next;
            }
        }
        if(carry > 0){
            sum.next = new Node(carry);
        }
        return bsum.next;
    }
}