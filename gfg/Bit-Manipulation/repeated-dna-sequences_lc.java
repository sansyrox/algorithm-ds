class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        final char[] a = s.toCharArray();
        List<String> result = new LinkedList<>();
        if(s.length() < 10) return result;
        int[] n = new int[s.length()-9];
        HashMap<Character,Integer> map = new HashMap<>();
        HashMap<Integer,Character> map2 = new HashMap<>();
        final int clearr = 0b00111111111111111111;
        map.put('A',0);
        map.put('C',1);
        map.put('G',2);
        map.put('T',3);

        map2.put(0,'A');
        map2.put(1,'C');
        map2.put(2,'G');
        map2.put(3,'T');

        int base = 0;
        for(int i = 0;i<10;i++){
            base <<= 2;
            base |= map.get(a[i]);
        }
        int len = n.length;
        n[0] = base;
        for(int i = 1;i<len;i++){
            n[i] = (((base&clearr)<<2) | map.get(a[9+i]));
            base = n[i];
        }
        Arrays.sort(n);
        int prev = Integer.MIN_VALUE;
        for(int i = 0;i<len;i++){
            if(prev == n[i]){
                StringBuilder ss = new StringBuilder();
                for(int j = 18;j>=0;j-=2){
                    ss.append(map2.get((n[i]>>j)&3));
                }
                result.add(ss.toString());
            }

            while((i < len) && (prev == n[i++]));
            i--;
            prev = n[i];

        }
        return result;
    }
}