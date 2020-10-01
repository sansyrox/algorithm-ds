/**
 * CREATED BY ROSHAN SINGH
 *
 * 2:28 AM  21/04/20
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
    static int dfs(boolean[][] mat,int i,int j,int x,int y,int n,int m){
        if((i == x) && (y == j)) return 0;
        mat[i][j] = false;
        int min = Integer.MAX_VALUE-1;
        if(((i+1) < n) && mat[i+1][j]) min = Math.min(min,dfs(mat,i+1,j,x,y,n,m));
        if(((j+1) < m) && mat[i][j+1]) min = Math.min(min,dfs(mat,i,j+1,x,y,n,m));
        if(((i-1) >= 0) && mat[i-1][j]) min = Math.min(min,dfs(mat,i-1,j,x,y,n,m));
        if(((j-1) >= 0) && mat[i][j-1]) min = Math.min(min,dfs(mat,i,j-1,x,y,n,m));
        return min+1;
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
            int m = s.nextInt();
            boolean[][] mat = new boolean[n][m];

            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++) mat[i][j] = (s.nextInt() == 1)?true:false;
            }
            int x = s.nextInt();
            int y = s.nextInt();
            if(!mat[0][0]){
                o.println("-1");
                continue;
            }
            int temp = dfs(mat,0,0,x,y,n,m);
            o.println((temp < n*m)?temp:"-1");
        }
        // end
        o.close();

    }
}