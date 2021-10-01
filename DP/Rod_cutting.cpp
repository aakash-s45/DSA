#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
#define f(itr,start,end) for(int itr=start;itr<end;itr++)

/*
solve(lenght[],cost[],rod,n){
    if(n is 0 or w is 0) return 0;
    if(rod>length[n-1])
        return max(  cost[n-1]+solve(length[],cost[],rod-length[n-1],n)  ,  solve(length[],cost[],rod,n-1));
    else 
        solve(length[],cost[],rod,n-1);
}
*/

//dp->array
//n->no. of rows
//w->no. of columns
//val->value to initialize array
void init_dp(vector<vec>&dp,int n,int w,int val){
    for (int i = 0; i <n+1; i++){
       vector<int> node(w+1,val);
       dp.push_back(node); 
    }
}
// lenArr->Lenght Array
// costArr->Cost Array
// Rodlength-> Length of rod
int RodCutting(vec lenArr,vec costArr,int RodLength){
    vector<vec> dp;
    int n=lenArr.size();
    init_dp(dp,n,RodLength,0);
    
    f(i,1,n+1){
        f(j,1,RodLength+1){
            if(j>=lenArr[i-1]){
                dp[i][j]=max(costArr[i-1]+dp[i][j-lenArr[i-1]], dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][RodLength];
}

void disp(vector<int> vec){
    for(int a:vec)cout<<a<<" ";
    cout<<endl;
}
void disp(vector<vector<int>> vec){
    for(vector<int> a:vec)disp(a);
}



int main(){

    vector<int> length_Array={1,2,3,4,5};
    vector<int> Cost_Array={5,2,0,0,0};
    int rodlength=5;
    cout<<RodCutting(length_Array,Cost_Array,rodlength);
    return 0;
}