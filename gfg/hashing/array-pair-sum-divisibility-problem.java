/**
 * CREATED BY ROSHAN SINGH
 *
 * 12:53 PM  31/03/20
 */
import java.io.*;
import java.util.*;
class Main{
    static class Reader // for number only problems
    {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }
        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (c == '.')
            {
                while ((c = read()) >= '0' && c <= '9')
                {
                    ret += (c - '0') / (div *= 10);
                }
            }
            if (neg)
                return -ret;
            return ret;
        }
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }
    public static void main(String[] args) throws IOException {
        Reader s = new Reader();
//        Reader s = new Reader("INPUT");
        OutputStream outputStream = System.out;
//        OutputStream outputStream = new FileOutputStream("OUTPUT");
        PrintWriter o = new PrintWriter(outputStream);
        // start
        int t = s.nextInt();
        int n,k;
        int mod;
        Map<Integer,Integer> map = new HashMap<>(200000,1);
        int[] a;
        boolean flag;
        while(t-->0){
            n = s.nextInt();
            a = new int[n];
            for(int i = 0;i<n;i++) a[i] = s.nextInt();
            k = s.nextInt();
            flag = true;
            if(n%2 != 0){
                o.println("False");
                continue;
            }
            if(k == 1 && n%2 == 0) {
                o.println("True");
                continue;
            }
            Arrays.sort(a);
            for (int i = 0; i < n; i++) {
                mod = a[i]%k;
                if(map.containsKey(mod)){
                    map.replace(mod,map.get(mod)+1);
                }else{
                    map.put(mod,1);
                }
            }
            for (int i = 0; i < n; i++) {
                if(map.get(a[i]%k) == 0) continue;
                mod = a[i]%k;
                if(mod == 0 && map.containsKey(mod) && map.get(mod) > 0 && map.get(mod)%2 == 0){
                    map.replace(mod,0);
                    continue;
                }else if(mod == 0 && map.containsKey(mod) && map.get(mod) > 0 && map.get(mod)%2 != 0 ){
                    break;
                }
                if(map.containsKey(k - mod) && (map.get(k - mod) > 0)){
                    map.replace(mod,map.get(mod) -1 );
                    map.replace(k - mod,map.get(k - mod) -1 );
                }
            }
            for(int i : a){
                if(map.get(i%k) != 0){
                    flag = false;
                    break;
                }
            }
            if(flag) o.println("True");
            if(!flag) o.println("False");
            map.clear();
        }
        // end
        o.close();

    }
}