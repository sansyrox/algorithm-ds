void sortColors(int A[], int n)  {     
            int n = A.size(); 
            int k = n - 1;
            int i = 0;
            for (; i < n; ++i)
            {
                if (A[i] != 0)
                {
                    break;
                }
            }

            int j = i;
            for (; i <= k; ++i)
            {
                if (A[i] == 0)
                {
                    swap(A[j++], A[i]);
                }
                else if (A[i] == 2)
                {
                    swap(A[i--], A[k--]);
                }
            }
        }


void Solution::sortColors(vector<int> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,j,k;
    int count[2]={0};
    for(i=0;i< a.size();i++)
    {
        if(a[i]==0)
            count[a[i]]++;
        else if(a[i]==1)
            count[a[i]]++;
        else if(a[i]==2)
            count[a[i]]++;
 
     }
 
   for(i=0;i < count[0];i++)
        a[i]=0;
    for(j=i;j < i+count[1];j++)
        a[j]=1;
    for(k=j;k < j+count[2];k++)
        a[k]=2;
 
  
 

}