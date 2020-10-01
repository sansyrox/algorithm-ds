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
        Queue<Character> q;
        Set<Character> set;
        int n;
        while(t-->0){
            n = s.nextInt();
            q = new LinkedList<>();
            set = new HashSet<>();

            for(int i = 0;i<n;i++){
                char c = s.next().toCharArray()[0];
//                System.out.println(set+" "+q);
                if(set.contains(c) && (q.size() == 0 || q.peek() == c)){
                    if(q.size() != 0) q.remove();
                    if(q.size() == 0) {
                        o.print(-1+" ");
                    }else{
                        o.print(q.peek()+" ");
                    }
//                    q.remove();
                }else{
                    if(!set.contains(c)){
                        q.add(c);
                        set.add(c);
                    }else{
                        q.remove(c);
                    }
                    o.print(q.peek()+" ");
                }
            }
            o.println("");
        }

        // end
        o.close();
    }
}