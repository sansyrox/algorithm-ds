// { Driver Code Starts
import java.util.*;


class First_Circular_tour
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t =sc.nextInt();
        while(t>0)
        {
            int n = sc.nextInt();
            sc.nextLine();
            String str = sc.nextLine();
            String arr[] = str.split(" ");
            int p[] = new int[n];
            int d[] = new int[n];
            int j=0;
            int k=0;
            for(int i=0; i<2*n; i++)
            {
                if(i%2 == 0)
                {
                    p[j]= Integer.parseInt(arr[i]);
                    j++;
                }
                else
                {
                    d[k] = Integer.parseInt(arr[i]);
                    k++;
                }
            }

            System.out.println(new GfG().tour(p,d));
            t--;
        }
    }
}// } Driver Code Ends
// In java function tour() takes two arguments array of petrol
// and array of distance
class GfG
{
    int tour(int petrol[], int distance[])
    {
        // Your code here
	/*
	//slow
	int sum = 0;
	boolean flag = true;
	int i = 0;
	for(;i<petrol.length;i++){
	    sum = petrol[i] - distance[i];
	    flag = true;
	    for(int j = (i+1)%petrol.length;j != i;j=(j+1)%petrol.length){
	        if(sum < 0){
	         flag = false;
	         break;
	        }
	        sum+=petrol[j]-distance[j];
	    }
	    if(flag) break;
	}
// 	System.out.println(sum);
	if(flag && sum >=0) return i;
	return -1;
	*/
        // fast
        int prev = 0,next = 0,start = 0;
        for(int i = 0;i<petrol.length;i++){
            next +=petrol[i]-distance[i];
            if(next < 0){
                prev += next;
                start = i+1;
                next = 0;
            }
        }
        return(next+prev >= 0)?start:-1;
    }
}