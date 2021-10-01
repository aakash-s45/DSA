#include "DP.h"

int LCS(string a,string b,int m,int n){
    if(m==0|| n==0)return 0;
    if(a[m-1]==b[n-1]) return 1+LCS(a,b,m-1,n-1);//if last char matches then take len-1 of both string
    else return max(LCS(a,b,m-1,n),LCS(a,b,m,n-1));// else take one string full other one len-1
}

int LCS_mem(string a,string b,int m,int n,dpArray &dp){
    if(m==0|| n==0)return 0;
    if(dp[m][n]!=-1)return dp[m][n];
    if(a[m-1]==b[n-1]) return dp[m][n]= 1+LCS_mem(a,b,m-1,n-1,dp);
    else return dp[m][n]=max(LCS_mem(a,b,m-1,n,dp),LCS_mem(a,b,m,n-1,dp));
}

int LCS_dp(string a,string b){
    int m=a.length(),n=b.length();
    dpArray dp;
    init_dp(dp,m,n,0);

    for(int i=1;i<m+1;i++){
        for (int j = 1; j < n+1; j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}


 
int main(){
    string a="Hellothisisproplayer";
    string b="ajygekanHellthisisof";
    int m=a.length();
    int n=b.length();
    // cout<<LCS(a,b,m,n);

    dpArray dp;
    init_dp(dp,m,n,-1);

    cout<<LCS_mem(a,b,m,n,dp)<<endl;
    cout<<LCS_dp(a,b);

    return 0;
}