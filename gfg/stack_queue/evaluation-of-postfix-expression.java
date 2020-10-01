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
            String a = s.next();
            Stack<Integer> stack = new Stack<>();
            for (int i = 0; i < a.length(); i++) {
                char in = a.charAt(i);
                if(in >= '0' && in <= '9'){
                    stack.push(in - '0');
                }else{
                    int aa = stack.pop();
                    int b = stack.pop();
                    switch(in){
                        case '+':
                            stack.push(b + aa);
                            break;
                        case '-':
                            stack.push(b - aa);
                            break;
                        case '*':
                            stack.push(b * aa);
                            break;
                        case '/':
                            stack.push(b / aa);
                            break;
                    }
                }
            }
            o.println(stack.pop());
        }
        // end
        o.close();
    }
}