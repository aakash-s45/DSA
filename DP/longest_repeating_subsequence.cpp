#include "DP.h"
int LRS(string a,string b){
    int m=a.length(),n=b.length();
    dpArray dp;
    init_dp(dp,m,n,0);
// only change here is that, we check if we get the same char in string somewhere else other than i
// so i!=j otherwise lcs will be whole string
    for(int i=1;i<m+1;i++){
        for (int j = 1; j < n+1; j++){
            if(a[i-1]==b[j-1] and i!=j) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}


 
int main(){
    // ABD is the repeating subsequence 
    // A B D are at more than one place in the string
    // E C occurs only single time
    // string a="AABEBCDD";
    string a="aabb";
    int m=a.length();


    cout<<LRS(a,a);

    return 0;
}