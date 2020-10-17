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
            a = new int[26];
            Arrays.fill(a,-1);
            String st = s.next();
            int count = 0;
            int max = 0;
            for(int i = 0;i<st.length();i++){
//                o.println(i);
                if(a[st.charAt(i)-'a'] == -1){
                    count++;
                    a[st.charAt(i)-'a'] = i;
                }else{
                    if(count > max) max = count;
                    count = 0;
                    i = a[st.charAt(i)-'a'];
                    Arrays.fill(a,-1);
                }
            }
            max = Math.max(count,max);
            o.println(max);
        }
        // end
        o.close();
    }
}