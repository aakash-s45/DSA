#include "DP.h"

string LCS_dp_print(string a,string b){
    int m=a.length(),n=b.length();
    dpArray dp;
    init_dp(dp,m,n,0);

    for(int i=1;i<m+1;i++){
        for (int j = 1; j < n+1; j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string res;
    int i=m,j=n;
    // we are follwing the way back to 00 from where it comes from, mn to 00
    while(i>0 and j>0){
        if(a[i-1]==b[j-1]){
            res.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i][j]==dp[i-1][j])i--;
            else j--;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}


 
int main(){
    string a="hellok";
    string b="yelosbfsjbfk";
    int m=a.length();
    int n=b.length();

    cout<<LCS_dp_print(a,b);

    return 0;
}