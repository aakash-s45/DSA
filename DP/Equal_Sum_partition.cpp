#include <bits/stdc++.h>
using namespace std;

void init_dp(vector<vector<int>>&dp,int n,int w,int val){
    for (int i = 0; i <n+1; i++){
       vector<int> node(w+1,val);
       dp.push_back(node); 
    }
}

bool EqualSumPartition(vector<int> val){
    int n=val.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=val[i];
    }
    // if sum is odd there is no poosible way to partition the array
    if(sum%2)return false;
    // if sum is even we have find if we can get sum = sum/2
    sum=sum/2;
    vector<vector<int>>dp;
    // initialization
    init_dp(dp,n,sum,0);
    // choice diagram
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < sum+1; j++){
            if(val[i-1]<=sum){
                dp[i][j]=max(dp[i-1][j-val[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    vector<int> val={11,5,5,1};
    cout<<EqualSumPartition(val);
    return 0;
}