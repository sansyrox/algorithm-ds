using namespace std;
#include<bits/stdc++.h>
#include<vector>
void edge(vector<int>graph[],int from,int to)
{   
    graph[from].push_back(to);
    graph[to].push_back(from) ;
    
}
int main()
 {
	//code
	int t;
	cin >> t;
	for (int i = 0;i<t;i++)
	{
	    int v,e ;
	    cin >> v >> e ;
	    vector<int> graph[v] ;
	    int a,b;
	    for (int j  = 0;j<e ;j++)
	    {
	        
	        cin >> a >> b;
	        edge(graph,a,b);
	    }
	    
	    for (int e =0;e<v;e++)
	    {
	        cout << e ;
	        for (int f = 0;f<graph[e].size();f++)
	        {   
	            cout << "-> " << graph[e][f] ;
	            
	        }
	        cout << '\n' ;
	    }
	    
	}
}