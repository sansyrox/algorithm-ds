/**
 * CREATED BY ROSHAN SINGH
 *
 * 10:00 PM  03/04/20
 */
import java.io.*;
import java.util.*;
class common{
    int n,m,a;
    common(int n,int m,int a){
        this.a = a;
        this.n = n;
        this.m = m;
    }
}
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
            int m = s.nextInt();
            int[] an = new int[n];
            int[] am = new int[m];
            LinkedList<common> ll = new LinkedList<>();
            for(int i = 0;i<n;i++) an[i] = s.nextInt();
            for(int i = 0;i<m;i++) am[i] = s.nextInt();
            int p1 = 0,p2 = 0;
            int sum1 = 0,sum2 = 0;
            int end1 = 0,end2 = 0;
            int sum = 0;
            while((p1 < n) && (p2 < m)){
                while ((p1 < n-1) && (an[p1] == an[p1+1])){
                    sum1+=an[p1];
                    p1++;
                }
                while ((p2 < m-1) && (am[p2] == am[p2+1])){
                    sum2+=am[p2];
                    p2++;
                }
                if(an[p1] < am[p2]){
                    sum1+=an[p1];
                    p1++;
                }else if(an[p1] > am[p2]){
                    sum2+=am[p2];
                    p2++;
                }else{
                    ll.add(new common(sum1,sum2,an[p1]));
                    p1++;
                    p2++;
                    sum1 = sum2 = 0;
                }
            }
            while(p1 < n){
                sum1+= an[p1];
                p1++;
            }
            while(p2 < m){
                sum2+= am[p2];
                p2++;
            }
            for(common i : ll){
                sum+=Math.max(i.n,i.m);
                sum+=i.a;
            }
            sum+=Math.max(sum1,sum2);
            o.println(sum);
        }
        // end
        o.close();

    }
}