/**
 * CREATED BY ROSHAN SINGH
 *
 * 9:23 PM  03/06/20
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
        while (t-->0){
            int n = s.nextInt();
            int[] a = new int[n];
            int[] prefix = new int[n+1];
            for(int i = 0;i<n;i++) a[i] = s.nextInt();
//            prefix[0] = a[0];
            for(int i = 1;i<=n;i++) prefix[i] = prefix[i-1]+a[i-1];
            int max_positive = Integer.MIN_VALUE,max = Integer.MIN_VALUE;
            int xp = 0,yn = 0;
            int x = 0,y = 0;
            for(int i = 0;i<=n;i++){
                if(prefix[i] > prefix[x]){
                    x = i;
                }else if(prefix[i] < prefix[y]){
                    if(prefix[x] - prefix[y] > prefix[xp] - prefix[yn]){
                        xp = x;
                        yn = y;
                    }else if((prefix[x] - prefix[y] == prefix[xp] - prefix[yn]) && x - y > xp - yn){
                        xp = x;
                        yn = y;
                    }
                    x = i;
                    y = i;
                }
            }

            System.out.println(xp+" "+yn+" "+Arrays.toString(prefix));
            if(prefix[x] - prefix[y] > prefix[xp] - prefix[yn]){
                xp = x;
                yn = y;
            }else if((prefix[x] - prefix[y] == prefix[xp] - prefix[yn]) && x - y > xp - yn){
                xp = x;
                yn = y;
            }
            for (int i = yn+1; i <= xp; i++) {
                o.print(a[i-1]+" ");
            }
            o.println("");
        }
        // end
        o.close();

    }
}