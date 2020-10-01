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
    static void  permute(String[] ch,boolean[] v,int n,String t,PrintWriter o){
        if(n == ch.length-1){
            for(int i = 0;i<ch.length;i++) {
                if(v[i] == false){
                    o.print(t+ch[i]+" ");
                }
            }
            return;
        }
        for(int i = 0;i<ch.length;i++){
            if(v[i] == false) {
                v[i] = true;
                permute(ch, v, n + 1, t + ch[i], o);
                v[i] = false;
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
        String[] ch;
        String n;
        boolean[] v;
        while(t-->0){
            n = s.next();
            ch = n.split("");
            v = new boolean[ch.length];
            Arrays.sort(ch);
            permute(ch,v,0,"",o);
            o.println("");
        }
        // end
        o.close();
    }
}