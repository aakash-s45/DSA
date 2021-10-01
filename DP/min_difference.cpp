#include "DP.h"

bool SubsetSum(vector<int> vec,int sum,vector<vector<int>>&dp){
    int n=vec.size();
    for (int i = 0; i < sum+1; i++){
        dp[0][i]=false;
    }
    for (int i = 0; i < n+1; i++){
        dp[i][0]=true;
    }
    disp(dp);
    cout<<endl;
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

int minDiff(vector<int>vec,vector<vector<int>>&dp){
    int sum=0;
    int n=vec.size();
    for (int i = 0; i < vec.size(); i++){
        sum+=vec[i];
    }
    init_dp(dp,n,sum/2,0);
    if(SubsetSum(vec,sum/2,dp) and sum%2==0)return 0;
    int mn=INT_MAX;

    for(int i=0;i<(dp.back().size());i++){
        if(dp.back()[i]){
            mn=min(mn,abs(sum-2*i));
        }
    }
    char ch='a';
    for(int i=0;i<dp.back().size();i++)cout<<i<<" ";
    cout<<endl;
    cout<<endl;
    disp(dp);
    cout<<endl;
    return mn;
}

int main(){
    // vector<int>vec={8, 4, 5, 7, 6, 2};
    // vector<int>vec={2,3,7,8,10};
    // vector<int>vec={5,1,6};
    // vector<int>vec={15,10,6};
    vector<int>vec={1,3,7};
    int n=vec.size();
    // int sum=12;
    vector<vector<int>>dp;
    // init_dp(dp,n,sum,0);
    // cout<<SubsetSum(vec,sum,dp);
    cout<<endl;
    cout<<minDiff(vec,dp);


    return 0;
}

