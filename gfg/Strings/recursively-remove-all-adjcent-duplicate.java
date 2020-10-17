/**
 * CREATED BY ROSHAN SINGH
 *
 */
import java.io.*;
import java.util.*;
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
    static void recursion(StringBuilder st,PrintWriter o) {
        int l = 0, r = 1;
        boolean f = false;
        while (r < st.length()) {
            if (st.charAt(l) == st.charAt(r)) {
                r++;
            } else {
                if ((r - l > 1) && st.charAt(l) == st.charAt(r - 1)) {
                    st.delete(l, r);
                    f = true;
                    r=l;
                    r++;
                } else {
                    l++;
                    r++;
                }
            }
        }
        if (r <= st.length() && (r - l > 1) && st.charAt(l) == st.charAt(r - 1)) {
            st.delete(l, r);
            f = true;
        }
        if(f)  recursion(st,o);
    }
    public static void main(String[] args) throws IOException {
        FastScanner s = new FastScanner();
//        FastScanner s = new FastScanner("INPUT");
        OutputStream outputStream = System.out;
//        OutputStream outputStream = new FileOutputStream("OUTPUT");
        PrintWriter o = new PrintWriter(outputStream);
        // start
        int t = s.nextInt();
        StringBuilder st;
        while(t-->0){
            st = new StringBuilder(s.next());
            recursion(st,o);
            o.println(st);
        }
        // end
        o.close();
    }
}