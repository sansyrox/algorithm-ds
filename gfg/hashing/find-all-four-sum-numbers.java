/**
 * CREATED BY ROSHAN SINGH
 *
 * 7:53 PM  30/03/20
 */
import java.io.*;
import java.util.*;
class Indx{
    int i,j,a;
    Indx(int i,int j,int a){
        this.i = i;
        this.j = j;
        this.a = a;
    }
//    boolean equals(Indx o){
//        return
//    }
    public String toString(){
        return i+" "+j;
    }
//    public int compare(Indx a,Indx b){
//        return b.a - a.a;
//    }
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
        int n,k;
        int[] a;
        Map<Integer,LinkedList<Indx>> map;
        LinkedList<Indx> ll;
        while (t-->0){
            boolean flag = true;
            n = s.nextInt();
            k = s.nextInt();
            a = new int[n];
            ll = null;
            map = new HashMap<>();
            for(int i = 0;i<n;i++){
                a[i] = s.nextInt();
            }
            Arrays.sort(a);
            int prev = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                prev = a[i];
                int prev2 = Integer.MAX_VALUE;
                for (int j = i+1; j < n; j++) {
                    if(i == j) continue;
                    if(prev2 == a[j]) continue;
                    prev2 = a[j]; // Here! Here i am really pissed off
                    if(map.containsKey(a[i]+a[j])){
                        map.get(a[i]+a[j]).add(new Indx(i,j,a[i]));
                    }else{
                        ll = new LinkedList<>();
                        ll.add(new Indx(i,j,a[i]));
                        map.put(a[i]+a[j],ll);
                    }
                }
            }
            prev = Integer.MAX_VALUE;
            String store = "";
            for (int i = 0; i < n; i++) {
                if(prev == a[i]) continue;
                prev = a[i];
                int prev3 = Integer.MAX_VALUE;
                for (int j = i+1; j < n; j++) {
                if(prev3 == a[j]) continue;
                prev3 = a[j];
                    if(map.containsKey(k - (a[i]+a[j]))){
                        ll = map.get(k - (a[i]+a[j]));
                        Collections.sort(ll,new Comparator<Indx>(){
                            public int compare(Indx a,Indx b){
                                return a.i - b.i;
                            }
                        });
                        Indx previ = new Indx(Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE);
                        for(Indx l : ll){
                            if(i != l.i && i != l.j && j != l.i &&  j != l.j && a[i] <= a[j] && a[j] <= a[l.i] && a[l.i] <= a[l.j]){
                                flag = false;
                                if(!store.equals(a[i]+" "+a[j]+" "+a[l.i]+" "+a[l.j]+" $")) o.print(a[i]+" "+a[j]+" "+a[l.i]+" "+a[l.j]+" $");
                                store = a[i]+" "+a[j]+" "+a[l.i]+" "+a[l.j]+" $";
                            }
                        }
                    }
                }
            }
            if(flag){
                o.println("-1");
            }else {
                o.println("");
            }
        }
        // end
        o.close();

    }
}