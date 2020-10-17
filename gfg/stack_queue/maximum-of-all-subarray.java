/**
 * CREATED BY ROSHAN SINGH
 *
 * 2:15 PM  11/03/20
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
        int[] a;
        Deque<Integer> q;
        while(t-->0){
            n = s.nextInt();
            k = s.nextInt();
            q = new LinkedList<>();
            a = new int[n];
            for(int i = 0;i<n;i++) a[i] = s.nextInt();
            int max = 0,max_i = 0;
            for(int i = 0;i<k;i++){
//                if(max < a[i]){
//                    max = a[i];
//                    max_i = i;
//                }
                if(!q.isEmpty()){
//                    System.out.println(q.peekLast());
                    while(!q.isEmpty() &&a[q.peekLast()] < a[i]){
                        q.removeLast();
                    }
                    q.addLast(i);
                }else{
                    q.add(i);
                }
            }
            o.print(a[q.peekFirst()]+" ");
            for(int i = k;i<n;i++){
//                System.out.println(q);
                if(q.peekFirst() < i-k+1){
                    q.removeFirst();
                }
                if(!q.isEmpty()){
                    while(!q.isEmpty() && a[q.peekLast()] < a[i]){
                        q.removeLast();
                    }
                    q.addLast(i);
                }else{
                    q.add(i);
                }
                o.print(a[q.peekFirst()]+" ");
            }
            o.println("");
        }
        // end
        o.close();

    }
}