import  java.util.*;
class Main {

    /**
     * variable (int) scope dosent affect much but relatively local variable are sligthly faster than global
     * array declare outside, declare inside, declare only once;
     * 1. seconds=0.941547077 @10000
     * 2. seconds=0.954818814
     * 3. seconds=0.935089128
     * 1. seconds=0.934383588
     * 2. seconds=0.947308943
     * 3. seconds=0.937106058
     * 1. seconds=0.559940717 (best) array size = 1000000
     * 2. seconds=0.559041774
     * 3. seconds=0.559218079
     * hash map new vs clear vs clear with initial capacity (1000,1000000) @ 1000
     * 1. seconds=0.440365071 (clear)
     * 2. seconds=0.472631056
     * 3. seconds=0.437689392
     * 4. seconds=0.409694285
     * 1. seconds=0.478848178 (1000)
     * 2. seconds=0.461226746
     * 3. seconds=0.466858871
     * 1. seconds=0.571006962 (100000)
     * 2. seconds=0.567077133
     * 3. seconds=0.57581293
     * 1. seconds=0.485090428 (new map)
     * 2. seconds=0.481773923
     * 3. seconds=0.504998868
     *
     * map interface vs hash map using clear
     * 1. seconds=0.469579008 (HashMap)
     * 2. seconds=0.470807337
     * 3. seconds=0.433021229
     * 4.1 seconds=0.459354837
     * 4.2 seconds=0.454871044
     * 4.3 seconds=0.445595249
     * 1. seconds=0.470084127
     * 2. seconds=0.454654277
     * 3. seconds=0.429143308
     * 4.1 seconds=0.454137176
     * 4.2 seconds=0.432527835
     * 4.3 seconds=0.408958883
     */
    public static void main(String[] args) {
        long total = 0L;
        int rounds = 30;
        int result = 0;
        Scanner s = new Scanner(System.in);
//        int N = s.nextInt();
        for (int T = 0;T<rounds;T++) {
            result = 0;
            long _zEr0tWoZeRo0nEoNenInEnInEnInE_ThIsIsOnLyFoRBeNcHmArKiNgNoThInGElSe = System.nanoTime();
//            HashMap<Integer,Integer> map = new HashMap<>();
            for (int i = 0; i < 1000; i++) {
                for (int j = 0; j < 10000; j++) {
//                    map.put(j,j*2);
                }
                for (int j = 0; j < 10000; j++) {
                    result+= 3*map.get(j);
                }
//                result += a.length;
//                map.clear();
            }
            _zEr0tWoZeRo0nEoNenInEnInEnInE_ThIsIsOnLyFoRBeNcHmArKiNgNoThInGElSe -= System.nanoTime();
            total+=_zEr0tWoZeRo0nEoNenInEnInEnInE_ThIsIsOnLyFoRBeNcHmArKiNgNoThInGElSe;
        }
        System.out.println("result="+result);
        System.out.println("seconds="+Math.abs(total/rounds)/(1000.0*1000.0*1000.0));
    }
}
