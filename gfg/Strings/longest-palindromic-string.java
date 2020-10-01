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
        while (t-->0){
            char[] a = (s.next()).toCharArray();
            int[][] dp = new int[a.length][a.length];
            int max = 0;
            int max_i = 0,max_j = 0;
            for (int i = 0; i < a.length; i++) {
                int y = i;
                for (int j = 0; y < a.length; j++,y++) {
                    System.out.println(i+" "+j);
                    if(i == 0){
                        dp[j][y] = 1;
                    }else if(i == 1){
                        dp[j][y] = (a[j] == a[y])?2:0;
                    }else{
                        dp[j][y] = (a[j] == a[y] && dp[j+1][y-1] > 0)?(2+dp[j+1][y-1]):0;
                    }
                    if(max < dp[j][y]){
                        max = dp[j][y];
                        max_i = j;
                        max_j = y;
                    }
                }
            }
            char[] out = new char[max];
            int i = 0,j = max-1;
            while(max_i <= max_j){
                out[i] = a[max_i];
                out[j] = a[max_j];
                i++;j--;
                max_i++;max_j--;
            }
            o.println(new String(out));
        }
        // end
        o.close();
    }
}