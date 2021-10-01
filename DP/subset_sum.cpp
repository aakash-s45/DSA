#include <bits/stdc++.h>
using namespace std;


void disp(vector<int> vec){
    for(int a:vec){
        cout<<a<<" ";
    }
    cout<<endl;
}
void disp(vector<vector<int>> vec){
    for(vector<int> a:vec){
        disp(a);
    }
}


bool SubsetSum(vector<int> vec,int sum,vector<vector<int>>&dp){
    int n=vec.size();
    for (int i = 0; i < sum+1; i++){
        dp[0][i]=false;
    }
    for (int i = 0; i < n+1; i++){
        dp[i][0]=true;
    }
    // disp(dp);
    // cout<<endl;
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < sum+1; j++){
            if(vec[i-1]<=j){
                dp[i][j]=dp[i-1][j-vec[i-1]]||dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
        
    }
    disp(dp);
    cout<<endl;
    return dp[n][sum];
    
    
}
void init_dp(vector<vector<int>>&dp,int n,int w,int val){
    for (int i = 0; i <n+1; i++){
       vector<int> node(w+1,val);
       dp.push_back(node); 
    }
}

int main(){
    vector<int>vec={2,3,7,8,10};
    int sum=12;
    int n=vec.size();
    vector<vector<int>>dp;
    init_dp(dp,n,sum,0);
    cout<<SubsetSum(vec,sum,dp);


    return 0;
}