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
        Map<Character,Integer> map = new HashMap<>();
        map.put('+',1);
        map.put('-',1);
        map.put('*',2);
        map.put('/',2);
        map.put('^',3);
        map.put('(',4);
        map.put(')',0);
        while (t-->0){
            char[] a = (s.next()).toCharArray();
            Stack<Character> stack = new Stack<>();
            for (int i = 0; i < a.length; i++) {
                if(map.containsKey(a[i])){
                    if(!stack.isEmpty()){
                        if(a[i] == ')'){
                            while (!stack.isEmpty()) {
                                char x = stack.pop();
                                if (x == '(') break;
                                    o.print(x);
                            }
                            continue;
                        }else if(map.get(stack.peek()) >= map.get(a[i])){
                            while (!stack.isEmpty() && map.get(stack.peek()) >= map.get(a[i]) && stack.peek() != '('){
                                o.print(stack.pop());
                            }
                        }
                    }
                    stack.push(a[i]);
                }else{
                    o.print(a[i]);
                }
            }
            while(!stack.isEmpty()) o.print(stack.pop());
            o.println("");
        }
        // end
        o.close();
    }
}