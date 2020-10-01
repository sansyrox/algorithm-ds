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
            char[] n = (s.next()).toCharArray();
            int[] hash_pat = new int[256];
            int[] hash_str = new int[256];
            int xlen = 0;
            for(char i : n){
                if(hash_pat[i] == 0) xlen++;
                hash_pat[i] = 1;
            }
            int count = 0,start = 0,min_len = Integer.MAX_VALUE,start_indx = -1;
            for (int i = 0; i < n.length; i++) {
                hash_str[n[i]]++;
                if(hash_pat[n[i]] != 0 && hash_pat[n[i]] >= hash_str[n[i]]) count++;
                if(count == xlen){
                    while (hash_str[n[start]] > hash_pat[n[start]] || hash_pat[n[start]] == 0){
                        if(hash_str[n[start]] > hash_pat[n[start]]) hash_str[n[start]]--;
                        start++;
                    }
                    int len = i-start+1;
                    if(min_len > len){
                        min_len = len;
                        start_indx = start;
                    }
                }
            }
            o.println(min_len);
        }
        // end
        o.close();
    }
}