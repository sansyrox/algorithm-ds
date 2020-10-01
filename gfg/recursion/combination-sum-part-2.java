/**
 * CREATED BY ROSHAN SINGH
 *
 * 12:29 AM  30/03/20
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
    static boolean flag = false;
    static void solve(int[] a,boolean[] v,int indx,int sum,int b,PrintWriter o){
        if(sum+a[indx] == b){
            flag = true;
            o.print("(");
            for (int i = 0; i < a.length; i++) {
                if(v[i] == true) o.print(a[i]+" ");
            }
            o.print(a[indx]+")");
            return;
        }else if(sum+a[indx] > b) return;
        v[indx] = true;
        for (int i = indx+1; i < a.length; i++) {
            if((v[i] == false) && (a[indx] <= a[i])) solve(a,v,i,sum+a[indx],b,o);
            while((i < a.length-1) && (a[i+1] == a[i]))i++;
        }
        v[indx] = false;
        return;
    }

    public static void main(String[] args) throws IOException {
        Reader s = new Reader();
//        Reader s = new Reader("INPUT");
        OutputStream outputStream = System.out;
//        OutputStream outputStream = new FileOutputStream("OUTPUT");
        PrintWriter o = new PrintWriter(outputStream);
        // start
        int t = s.nextInt();
        int n,b;
        int[] a;
        boolean[] v;
        while (t-->0){
            n = s.nextInt();
            a = new int[n];
            v = new boolean[n];
            flag = false;
            for (int i = 0; i < n; i++) {
                a[i] = s.nextInt();
            }
            Arrays.sort(a);
            b = s.nextInt();
            for (int i = 0; i < n; i++) {
                solve(a,v,i,0,b,o);
                while((i < a.length-1) && (a[i+1] == a[i]))i++;
            }
            if(flag){
                o.println("");
            }else{
                o.println("Empty");
            }
        }
        // end
        o.close();

    }
}