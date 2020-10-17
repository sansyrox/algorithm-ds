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
    static void helper(char[][] a,boolean[][] visited,int x,int y){
        if(visited[x][y]) return;
        visited[x][y] = true;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if(Math.abs(i) != Math.abs(j) && (x+i) >= 0 && (y+j) >= 0 && (x+i) < a.length && (y+j) < a[0].length && a[x+i][y+j] == 'X') helper(a,visited,x+i,y+j);
            }
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
            int m = s.nextInt();
            char[][] a = new char[n][m];

            for (int i = 0; i < n; i++) {
                a[i] = s.next().toCharArray();
            }
            boolean[][] visited = new boolean[n][m];
            int count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(a[i][j] == 'X' && !visited[i][j]){
                        helper(a,visited,i,j);
                        count++;
                    }
                }
            }
            o.println(count);
        }
        // end
        o.close();
    }
}