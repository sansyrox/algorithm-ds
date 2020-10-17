/*
 Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

 Input:
 The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

 Output:
 For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring subarray from the left if sum equals to subarray, else print -1.

 Constraints:
 1 <= T <= 100
 1 <= N <= 107
 1 <= Ai <= 1010

 Example:
 Input:
 2
 5 12
 1 2 3 7 5
 10 15
 1 2 3 4 5 6 7 8 9 10
 Output:
 2 4
 1 5

 Explanation :
 Testcase1: sum of elements from 2nd position to 4th position is 12
 Testcase2: sum of elements from 1st position to 5th position is 15
 */
import java.util.*;
class Main {
    public static void main(String[] args){
       Scanner s = new Scanner(System.in);
       int t = s.nextInt();
       int n,S;
       int[] a;
       while (t--> 0){
           n = s.nextInt();
           S = s.nextInt();
           a = new int[n];
           for (int i = 0; i < n; i++) {
               a[i] = s.nextInt();
           }
           int counti = 0,countj = 0,sum = a[0];
           boolean f = true;
           while(sum != S){

               if(sum < S){
                   countj++;
                   if(countj == n){
                       System.out.println(-1);
                       f = false;
                       break;
                   }
                   sum+=a[countj];

               }else{
                   sum-=a[counti];
                   counti++;
               }
               if(counti == countj) sum = a[countj];
//               System.out.println(counti+" "+countj+" "+sum);

           }
           if(f)
           if(sum == S) {
               System.out.println(counti + 1 + " " + (countj + 1) + " ");
           }else {
               System.out.println(-1);
           }
       }
    }

}
