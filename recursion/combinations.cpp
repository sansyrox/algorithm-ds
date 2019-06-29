#define vvi vector<vector<int> >
#define vi vector<int>
#define pb push_back

set<vi> ans;

void generation(vi &mainstring, vi &temp, int k, int i){

    if(i>=mainstring.size() and k!=0){
        return;
    }

    if(temp.size()==k){

        ans.insert(temp);
        return;
    }

    for(int j=i; j<mainstring.size(); j++){
        temp.push_back(mainstring[j]);
        generation(mainstring,temp,k,i+1);
        temp.pop_back();
        // generation(mainstring,temp,k,i+1);
    }
}

vector<vector<int> > Solution::combine(int A, int B) {
    vi mainstring;
    
    
    for(int i=1; i<=A; i++) mainstring.pb(i);
    vi temp;
    generation(mainstring,temp,B,0);

    vvi ansf;
    if(A==1 and B!=1|| A==0){
        return ansf;
    }
    
    if(A==1 and B==1){
        vector<int> t;
        t.pb(1);
        ansf.pb(t);
        
        return ansf;
    }
    
    for(auto i:ans){
        ansf.push_back(i);
    }
    
    return ansf;
    
}



 void combination(vector<vector<int>> &res,vector<int> &subset,int index,int A,int B)
{
if(subset.size()==B)
{
res.push_back(subset); 
    }
 
 
 
for(int i=index;i<=A;i++)
{
    subset.push_back(i);
 
    combination(res,subset,i+1,A,B);
   
    subset.pop_back();
    
}
}
 
vector<vector<int> > Solution::combine(int A, int B) {
 
vector<vector<int>> res;
if(B>A)
{
    return res;
    
}
vector<int> subset;
int index=1;
combination(res,subset,index,A,B);
 
return res;
}