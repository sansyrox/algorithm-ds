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
        int t,n;
        Map<Character,Integer> map;
        StringBuilder str;
        t = s.nextInt();
        final char[] a = new char[]{'!', '#' ,'$' ,'%' ,'&' ,'*' ,'@', '^', '~' };
        while(t-->0){
            str = new StringBuilder();
            n = s.nextInt();
            map = new HashMap<>();
            for(int i = 0;i<n;i++){
                char[] temp = s.next().toCharArray();
                if(map.containsKey(temp[0])){
                    map.put(temp[0],map.get(temp[0])+1);
                }else{
                    map.put(temp[0],1);
                }
            }

            for(int i = 0;i<n;i++){
                char[] temp = s.next().toCharArray();
                if(map.containsKey(temp[0])){
                    map.put(temp[0],map.get(temp[0])+1);
                }else{
                    map.put(temp[0],1);
                }
            }
            int count = 0;
            while(count<a.length){
                if(map.containsKey(a[count]) && map.get(a[count])>=2){
                    str.append(a[count]+" ");
                    map.put(a[count],map.get(a[count])-2);
                }else{
                    count++;
                }
            }
            o.println(str);
            o.println(str);

        }
        // end
        o.close();
    }
}