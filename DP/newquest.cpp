#include "DP.h"

// int maxcoin(vector<int> coin,int n,int sum,vector<vector<int>>&dp){
//     if(sum==0 || n==0)return 0;
//     if(dp[n][sum]!=-1)return dp[n][sum];
//     if(sum>=coin[n-1])return dp[n][sum]=max(1+maxcoin(coin,n-1,sum-coin[n-1],dp),maxcoin(coin,n-1,sum,dp));
//     else return dp[n][sum]=maxcoin(coin,n-1,sum,dp);
// }

int maxcoin(vector<int> coin,int n,int sum,vector<vector<int>>&dp){
    if(n==0 and sum!=0){
        return INT_MAX-n-10;
    }
    if(sum==0)return 0;

    if(dp[n][sum]!=-1)return dp[n][sum];

    if(sum>=coin[n-1])return dp[n][sum]=min(1+maxcoin(coin,n-1,sum-coin[n-1],dp),maxcoin(coin,n-1,sum,dp));
    else return dp[n][sum]=maxcoin(coin,n-1,sum,dp);
}

bool SubsetSum(vector<int> vec,int sum,vector<vector<int>>&dp){
    int n=vec.size();
    for (int i = 0; i < sum+1; i++){
        dp[0][i]=false;
    }
    for (int i = 0; i < n+1; i++){
        dp[i][0]=true;
    }
    
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
    return dp[n][sum];
}

int minDiff(vector<int>vec,vector<vector<int>>&dp){

    int sum=0;
    int n=vec.size();
    for (int i = 0; i < vec.size(); i++){
        sum+=vec[i];
    }
    init_dp(dp,n,sum/2,0);
    //
    if(SubsetSum(vec,sum/2,dp) and sum%2==0){
        int half_sum=sum/2;
        reinit_dp(dp,-1);
        return maxcoin(vec,n,half_sum,dp);
    }
    

    int mn=INT_MAX;
    int mincol=0;
    for(int i=0;i<(dp.back().size());i++){
        if(dp.back()[i]){
            if(abs(sum-2*i)<mn){
                mn=abs(sum-2*i);
                mincol=i;
            }
        }
    }
    reinit_dp(dp,-1);
    return maxcoin(vec,n,mincol,dp);
}

int solve(const vector<int> &A) {
    vector<vector<int>>dp;
    return minDiff(A,dp);
}


int main(){
    // vec v={ 11, 10, 8, 6, 8, 11, 1, 10, 2, 3, 8, 3, 8, 12, 11, 1, 7, 5, 5, 12, 9, 4, 10, 3, 3, 3, 8, 8, 8, 6, 7, 7, 7, 6, 4, 2, 5, 8, 11, 10, 10, 10, 12, 9, 2, 3, 9, 12, 7, 6, 11, 8, 9, 9, 10, 3, 3, 5, 2, 10, 10, 9, 4, 9, 6, 11, 10, 2, 6, 1, 4, 7, 10, 3, 4, 3, 9, 4, 3, 8, 1, 1, 3 };
    vec v={8,5,3,7};
    cout<<solve(v);
    return 0;
}
