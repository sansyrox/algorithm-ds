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
        while(t-->0){
            int n = s.nextInt();
            int m = s.nextInt();
            char[] p = s.next().toCharArray();
            char[] q = s.next().toCharArray();
            int[][] dp = new int[n+1][m+1];
            for (int i = 0; i <= m; i++) dp[0][i] = i;
            for (int i = 0; i <= n; i++) dp[i][0] = i;
            for(int i = 1;i<=n;i++)
                for (int j = 1; j <= m; j++) {
                    if(p[i-1] == q[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = Math.min(Math.min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                    }
                }
//            for (int[] i : dp)System.out.println(Arrays.toString(i));
            o.println(dp[n][m]);
        }
        // end
        o.close();
    }
}