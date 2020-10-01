import java.util.*;
//VERDICT : Math.pow() >> power()
class Main {
    static final double power(double base,int exp){
        double t1 = 1,t2 = 0;
        for(int i = 0;i++<exp;){
            for(double j = 0;j++<base;){
                t2+=t1;
            }
            t1 = t2;
            t2 = 0;
        }
        return t1;
    }
    public static void main(String[] args) {
        Random rand = new Random();
        long _zEr0tWoZeRo0nEoNenInEnInEnInE_ThIsIsOnLyFoRBeNcHmArKiNgNoThInGElSe = System.nanoTime();
        double result = 0L;
        for(int j = 0;j<1000;j++)
        for (int i = 2; i <40; i++) {
//        result = power(i,60);
            result = Math.pow(i,60);
        }
        _zEr0tWoZeRo0nEoNenInEnInEnInE_ThIsIsOnLyFoRBeNcHmArKiNgNoThInGElSe -= System.nanoTime();
        System.out.println("result="+result);
        System.out.println("seconds="+Math.abs(_zEr0tWoZeRo0nEoNenInEnInEnInE_ThIsIsOnLyFoRBeNcHmArKiNgNoThInGElSe)/(1000.0*1000.0*1000.0));
    }
}
