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
    public static void main(String[] args) throws IOException {
        FastScanner s = new FastScanner();
//        FastScanner s = new FastScanner("INPUT");
        OutputStream outputStream = System.out;
//        OutputStream outputStream = new FileOutputStream("OUTPUT");
        PrintWriter o = new PrintWriter(outputStream);
        // start
        int t = s.nextInt();
        int[] a;
        while(t-->0){
            String st = s.nextLine();
            a = new int[256];
            for(int i = 0;i<st.length();i++){
                if(a[st.charAt(i)] == 0){
                    o.print(st.charAt(i));
                    if(!('a' <= st.charAt(i) && 'z' >= st.charAt(i)) && !('A' <= st.charAt(i) && 'Z' >= st.charAt(i))){
                        a[st.charAt(i)] = 1;
                    } else {
                        if('a' <= st.charAt(i) && 'z' >= st.charAt(i)){
                            a[st.charAt(i)] = 1;
                            a['A'+st.charAt(i)-'a'] = 1;
                        } else{
                                a[st.charAt(i)] = 1;
                                a['a'+st.charAt(i)-'A'] = 1;
                        }
                    }
                }else{
                    if(!('a' <= st.charAt(i) && 'z' >= st.charAt(i)) && !('A' <= st.charAt(i) && 'Z' >= st.charAt(i))){
                        a[st.charAt(i)] = 0;
                    } else {
                        if('a' <= st.charAt(i) && 'z' >= st.charAt(i)){
                            a[st.charAt(i)] = 0;
                            a['A'+st.charAt(i)-'a'] = 0;
                        } else{
                            a[st.charAt(i)] = 0;
                            a['a'+st.charAt(i)-'A'] = 0;
                        }
                    }
                }
            }
            o.println("");
        }
        // end
        o.close();
    }
}