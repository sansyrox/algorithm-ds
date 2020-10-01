* CREATED BY ROSHAN SINGH
        *
        */
import java.io.*;
import java.util.*;
class chr {
    char c;
    int freq;
    chr(char c,int freq) {
        this.c = c;
        this.freq = freq;
    }
}
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
        char[] in;
        int[] alpha;
        PriorityQueue<chr> max;
        while(t-->0){
            alpha = new int[27];
            max = new PriorityQueue<>(new Comparator<chr>(){
                public int compare(chr a,chr b){
                    return b.freq - a.freq;
                }
            });
            in = s.next().toCharArray();
            for(char i : in) alpha[i-'a']++;
            for(int i = 0;i<27;i++){
                if(alpha[i] > 0) max.add(new chr((char)(i+'a'),alpha[i]));
            }
            chr temp = null ,prev = null;
            while(!max.isEmpty() /*|| (max.size() == 1 && max.peek().fre)*/){
                temp = max.poll();
                if(prev != null && prev.freq > 0){
                    max.add(prev);
                }
                temp.freq--;
                prev = temp;
            }
            if(temp.freq == 0){
                o.println("1");
            }else{
                o.println("0");
            }


        }
        // end
        o.close();
    }
}