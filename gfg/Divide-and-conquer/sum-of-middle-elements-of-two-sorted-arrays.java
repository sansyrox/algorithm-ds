/**
 * CREATED BY ROSHAN SINGH
 *
 * 9:22 PM  07/04/20
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
        while(t-->0){
            int n = s.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            for(int i = 0;i<n;i++) a[i] = s.nextInt();
            for(int i = 0;i<n;i++) b[i] = s.nextInt();

            int l1 = 0,l2 = 0,r1 = n-1,r2 = n - 1,mid1 = 0,mid2 = 0;
//            mid1 = (l1+r1)/2;
//            if((n&1) == 0) mid2 = (l2+r2)/2-1;
//            if((n&1) != 0) mid2 = (l2+r2)/2;
            while(l1 <= r1 && l2 <= r2 && (r1-l1) != 1 && (r2-l2) != 1 ){
                mid1 = (l1+r1)/2;
                mid2 = (l2+r2)/2;
                if(a[mid1] > b[mid2]){
                    r1 = mid1;
                    l2 = mid2;
                }else if(a[mid1] < b[mid2]){
                    r2 = mid2;
                    l1 = mid1;
                } else{
                    break;
                }
            }
//            System.out.println(l1+" "+r1+" "+l2+" "+r2);
            o.println(Math.max(a[l1],b[l2])+Math.min(a[r1],b[r2]));
        }
        // end
        o.close();

    }
}