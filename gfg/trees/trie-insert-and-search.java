/**
 * CREATED BY ROSHAN SINGH
 *
 */
import java.io.*;
import java.util.*;

class Node {
    Node[] children;
    boolean isEnd;
    public Node(){
        isEnd = false;
        children = new Node[256];
    }
}

class Main{
    static class FastScanner {  // for string + number
        BufferedReader br;
        StringTokenizer st;
        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        public FastScanner(String file)  throws IOException{
            br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException  e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    //---
    static boolean search(Node root,String str,int indx){
        if(indx == str.length()-1){
            if(root.isEnd){
                return true;
            }else {
                return false;
            }
        }
        if(root.children[str.charAt(indx)] != null){
            return search(root.children[str.charAt(indx)],str,indx+1);
        }else{
            return false;
        }
    }

    static void insert(Node root,String str,int indx){
        if(str.length() == 0){
            root.isEnd = true;
            return;
        }
        if(indx == str.length()-1){
            root.isEnd = true;
            return;
        }
        if(root.children[str.charAt(indx)] != null){
            insert(root.children[str.charAt(indx)],str,indx+1);
        }else{
            root.children[str.charAt(indx)] = new Node();
            insert(root.children[str.charAt(indx)], str, indx + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner s = new FastScanner();
//        FastScanner s = new FastScanner("INPUT");
        OutputStream outputStream = System.out;
//        OutputStream outputStream = new FileOutputStream("OUTPUT");
        PrintWriter o = new PrintWriter(outputStream);
        // start
        int t = s.nextInt();
        while (t-->0){
            int n = s.nextInt();
            String[] a = new String[n];
            for (int i = 0; i < n; i++) {
                a[i] = s.next();
            }
            String find = s.next();
            Node root = new Node();
            for (String i : a) insert(root,i,0);
            o.println((search(root,find,0))?1:0);
        }
        // end
        o.close();
    }
}