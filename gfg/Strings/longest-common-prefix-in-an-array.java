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
        int t = s.nextInt(),n;
        String[] st;
        while(t-->0){
            n = s.nextInt();
            int count = 0;
            int ptr = 0;
            boolean x = true;
            st = new String[n];
            for(int i = 0;i<n;i++) st[i] = s.next();
            for(char j : st[0].toCharArray()){
                x = true;
                for(int i = 0;i<n;i++){
                    if(ptr >= st[i].length() || st[i].charAt(ptr) != j){
                        x = false;
                        break;
                    }
                }
                if(!x){
//                    o.println(st[0].substring(0,count));
                    break;
                }else{
                    count++;
                    ptr++;
                }
            }
//            o.println(count+" "+ptr+" "+x);
            if(count == 0) {
                o.println("-1");
            }else{
                o.println(st[0].substring(0,count));
            }
        }
        // end
        o.close();
    }
}