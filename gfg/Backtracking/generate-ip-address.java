// { Driver Code Starts


import java.util.*;
class GenIP {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            Solution sln = new Solution();
            ArrayList<String> str = sln.genIp(s);
            Collections.sort(str);
            for (String u : str) {
                System.out.println(u);
            }
        }
    }
}// } Driver Code Ends
/*complete the Function*/

class Solution {
    static void ip(String s,int d,int indx,ArrayList<String> out,StringBuilder str){
        if(d == 3){
            if(s.charAt(0) != '0' && s.substring(0,indx).length() <=3 && s.substring(0,indx).length() != 0){
                if(Integer.parseInt(s.substring(0,indx)) <= 255){
                    StringBuilder tmp = new StringBuilder(str);
                    tmp.append((new StringBuilder(s.substring(0,indx))).reverse());
                    out.add(tmp.reverse().toString());
                }
            }else if(s.charAt(0) == '0' && indx == 1){
                StringBuilder tmp = new StringBuilder(str);
                tmp.append("0");
                out.add(tmp.reverse().toString());
            }
            return;
        }
        for(int i = indx-1;i>=0;i--){
            StringBuilder sub = new StringBuilder(s.substring(i,indx));
            if(sub.charAt(0) != '0' && sub.length() <=3){
                if(Integer.parseInt(sub.toString()) <= 255){
                    StringBuilder tmp = new StringBuilder(str);
                    tmp.append(sub.reverse()).append(".");
                    ip(s,d+1,i,out,tmp);
                }
            }else if(sub.charAt(0) == '0' && (indx - i) == 1){
                StringBuilder tmp = new StringBuilder(str);
                tmp.append("0.");
                ip(s,d+1,i,out,tmp);
            }
        }
    }
    public ArrayList<String> genIp(String s) {
        // code here
        ArrayList<String> out = new ArrayList<>();
        StringBuilder tmp = new StringBuilder();
        ip(s,0,s.length(),out,tmp);
        Collections.sort(out);
        return out;
    }
}