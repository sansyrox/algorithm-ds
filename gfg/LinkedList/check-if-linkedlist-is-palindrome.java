// { Driver Code Starts
import java.util.*;

class Node
{
    int data;
    Node next;

    Node(int d)
    {
        data = d;
        next = null;
    }
}

class Is_LinkedList_Palindrom
{
    Node head;

    /* Function to print linked list */
    void printList(Node head)
    {
        Node temp = head;
        while (temp != null)
        {
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }


    /* Inserts a new Node at front of the list. */
    public void addToTheLast(Node node)
    {

        if (head == null)
        {
            head = node;
        } else
        {
            Node temp = head;
            while (temp.next != null)
                temp = temp.next;

            temp.next = node;
        }
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t>0)
        {
            int n = sc.nextInt();
            //int k = sc.nextInt();
            Is_LinkedList_Palindrom llist = new Is_LinkedList_Palindrom();
            //int n=Integer.parseInt(br.readLine());
            int a1=sc.nextInt();
            Node head= new Node(a1);
            Node tail = head;
            for (int i = 1; i < n; i++)
            {
                int a = sc.nextInt();
                tail.next = new Node(a);
                tail = tail.next;
            }

            Palindrome g = new Palindrome();
            if(g.isPalindrome(head) == true)
                System.out.println(1);
            else
                System.out.println(0);
            t--;
        }

    }
}



// } Driver Code Ends
/* Structure of class Node is
class Node
{
	int data;
	Node next;

	Node(int d)
	{
		data = d;
		next = null;
	}
}*/

class Palindrome
{
    // Function to check if linked list is palindrome
    static boolean method1(Node head){
        Node curr = head;
        Node prev,temp,second,first;
        prev = temp = null;
        int len = 0;
        int count = 0;
        while(curr != null && len++ >= 0 && (curr = curr.next) != (new Node(0)));
        curr = head;
        if(len == 1)return true;
        while(count < len/2){
            temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
            count++;
        }
        second = temp;
        first = prev;
        if(len%2 != 0) second = second.next;
        while(first != null && second != null && first.data == second.data){
            first = first.next;
            second = second.next;
        }
        boolean result;
        if(first == null && second == null){
            result = true;
        }else {
            result = false;
        }
        count = 0;
        second = temp;
        first = prev;
        while(count < len/2){
            temp = first.next;
            first.next = second;
            second = first;
            first = temp;
            count++;
        }
        return result;


    }
    static boolean method2(Node head){
        Node curr = head;
        Stack<Integer> s = new Stack<>();
        while(curr != null){
            s.push(curr.data);
            curr = curr.next;
        }
        curr = head;
        int top;
        while(curr != null){
            top = s.pop();
            if(top != curr.data) return false;
            curr = curr.next;
        }
        return true;
    }
    boolean isPalindrome(Node head)
    {
        //Your code here
        return method2(head);
    }
}

