/**
 * CREATED BY ROSHAN SINGH
 *
 * 3:51 PM  30/03/20
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
        int n1,n2,n3;
        long[] a1,a2,a3;
        Set<Long> set;
        while(t-->0){
            n1 = s.nextInt();
            n2 = s.nextInt();
            n3 = s.nextInt();
            a1 = new long[n1];
            a2 = new long[n2];
            a3 = new long[n3];
            set = new HashSet<>();
            for (int i = 0; i < n1; i++) {
                a1[i] = s.nextLong();
            }
            for (int i = 0; i < n2; i++) {
                a2[i] = s.nextLong();
            }
            for (int i = 0; i < n3; i++) {
                a3[i] = s.nextLong();
            }
            int x1,x2;
            x1 = x2 = 0;
            while(x1 < n1 && x2 < n2){
                if(a1[x1] == a2[x2]){
                    set.add(a1[x1]);
                    x1++;
                    x2++;
                }else{
                    if(a1[x1] < a2[x2]){
                        x1++;
                    }else{
                        x2++;
                    }
                }
            }
            boolean flag = true;
            long prev = Long.MAX_VALUE;
                for (long i : a3) {
                    if(i == prev) continue;
                    if (set.contains(i)){
                        flag = false;
                        o.print(i + " ");
                    }
                    prev = i;
                }
                if(flag) o.print("-1");
            o.println("");
        }
        // end
        o.close();

    }
}