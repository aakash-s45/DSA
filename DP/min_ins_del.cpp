#include "DP.h"

int LCS_dp(string &a,string &b){
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

int Min_Required(string &a,string &b){
    int lcs=LCS_dp(a,b);
    return (b.length()-lcs)+(a.length()-lcs);
}

int main(){
    string a="Hello";
    string b="yellow";
    int m=a.length();
    int n=b.length();

    // cout<<LCS_dp(a,b)<<endl;
    cout<<Min_Required(a,b);

    return 0;
}