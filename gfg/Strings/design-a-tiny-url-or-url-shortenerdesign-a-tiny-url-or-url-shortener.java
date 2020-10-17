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
        long a;
        char[] b = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789".toCharArray();
        Stack<Character> stack;
        while(t-->0){
            a = s.nextLong();
            stack = new Stack<>();
            long temp = 0;
            while(a > 0){
                stack.push(b[(int)a%62]);
                a = a/62;
            }
            int count = stack.size()-1,x;
            while(!stack.isEmpty()){
                char i = stack.pop();
                if('a' <= i && i <= 'z'){
                    x = i - 'a';
                }else if('A' <= i && i <= 'Z'){
                    x = i - 'A'+'z'-'a'+1;
                }else{
                    x = i - '0'+'z'+'Z'-'a'-'A'+2;
                }
//                o.println(x);
                temp+= Math.pow(62,count)*x;
                count--;
                o.print(i);
            }
            o.println("");
            o.println(temp);
        }
        // end
        o.close();
    }
}