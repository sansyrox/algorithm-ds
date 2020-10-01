/**
 * CREATED BY ROSHAN SINGH
 *
 */
import java.io.*;
import java.util.*;
class trie{
    Map<Character,trie> map;
    boolean end;
    trie(){
        map = new HashMap<>();
        end = false;
    }
    static boolean contains(String s,trie t,int indx){
        if(s.length() == indx) return true;
        if(t.map.containsKey(s.charAt(indx))) return contains(s,t.map.get(s.charAt(indx)),indx+1);
        return false;
    }
    public String toString(){
        return '-'+map.toString()+'+';
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

    static void buildTrie(char[][] str,boolean[][] visited,trie t,int x,int y,int n,int m,int max){
        if(max == 0) return;
        visited[x][y] = true;
        trie tmp = new trie();
        if(x+1 < n && visited[x+1][y] == false){
            buildTrie(str,visited,tmp,x+1,y,n,m,max-1);
        }
        if(x-1 >= 0 && visited[x-1][y] == false){
            buildTrie(str,visited,tmp,x-1,y,n,m,max-1);
        }
        if(y+1 < m && visited[x][y+1] == false){
            buildTrie(str,visited,tmp,x,y+1,n,m,max-1);
        }
        if(y-1 >= 0 && visited[x][y-1] == false){
            buildTrie(str,visited,tmp,x,y-1,n,m,max-1);
        }
        if(x-1 >= 0 && y-1 >=0 && visited[x-1][y-1] == false){
            buildTrie(str,visited,tmp,x-1,y-1,n,m,max-1);
        }
        if(x+1 < n && y-1 >=0 && visited[x+1][y-1] == false){
            buildTrie(str,visited,tmp,x+1,y-1,n,m,max-1);
        }
        if(x-1 >= 0 && y+1 < m && visited[x-1][y+1] == false){
            buildTrie(str,visited,tmp,x-1,y+1,n,m,max-1);
        }
        if(x+1 < n && y+1 < m && visited[x+1][y+1] == false){
            buildTrie(str,visited,tmp,x+1,y+1,n,m,max-1);
        }
        if(t.map.containsKey(str[x][y])){
            t.map.get(str[x][y]).map.putAll(tmp.map);
        }else{
            t.map.put(str[x][y],tmp);
        }
        visited[x][y] = false;
    }
    public static void main(String[] args) throws IOException {
        FastScanner s = new FastScanner();
//        FastScanner s = new FastScanner("INPUT");
        OutputStream outputStream = System.out;
//        OutputStream outputStream = new FileOutputStream("OUTPUT");
        PrintWriter o = new PrintWriter(outputStream);
        // start
        int t = s.nextInt();
        while(t-->0){
            int x = s.nextInt();
            String[] str = new String[x];
            for(int i = 0;i<x;i++) str[i] = s.next();
            int n = s.nextInt();
            int m = s.nextInt();
            char[][] bog = new char[n][m];
            for(int i = 0;i<n;i++)
                for(int j = 0;j<m;j++)
                    bog[i][j] = s.next().toCharArray()[0];
            ;
            boolean[][] visited = new boolean[n][m];
            trie root = new trie();
            Arrays.sort(str);
            int max = str[x-1].length();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    buildTrie(bog,visited,root,i,j,n,m,max+2);
                }
            }
            boolean flag = true;
            String prev = "";
            for(String i : str){
                if(prev.equals(i)) continue;
                if(trie.contains(i,root,0)){
                    o.print(i+" ");
                    flag = false;
                }
                prev = i;
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