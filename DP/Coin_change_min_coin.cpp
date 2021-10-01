#include "DP.h"

int MinCoin(vector<int> vec,int sum,vector<vector<int>>&dp){
    int n=vec.size();
    for (int i = 1; i < sum+1; i++){
        dp[0][i]=INT_MAX-5;
    }
    
    for (int i = 1; i < sum+1; i++){
        if(i%vec[0]==0)dp[1][i]=i/vec[0];
        else dp[1][i]=INT_MAX-5;
    }

    // disp(dp[1]);
    for (int i = 2; i < n+1; i++){
        for (int j = 1; j < sum+1; j++){
            if(vec[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-vec[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        } 
    }
    // disp(dp);
    cout<<endl;
    return dp[n][sum];
}

int main(){
    vector<int>vec={8, 4, 5, 7, 6, 2};
    // vector<int>vec={2,2,1};
    int sum=16;
    int n=vec.size();

    vector<vector<int>>dp;
    init_dp(dp,n,sum,0);

    cout<<MinCoin(vec,sum,dp);

    return 0;
}