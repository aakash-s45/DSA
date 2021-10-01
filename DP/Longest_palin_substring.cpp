#include "DP.h"

/*
a bbsbb d
a bbsbb
*/

// returns length of longest palindromic substring
int LPSS(string &a,int start,int end){
    if(start>end)return 0;
    if(start==end)return 1;
    if(a[start]==a[end]){
        int rem = end-start-1;
        // if char at end == char at start
        // try checking for internal string if it matches or not(calculate LPSS)
        if(LPSS(a,start+1,end-1)==rem)return rem+2; 
    }
    // try skipping 1st char and last char
    return max(LPSS(a,start,end-1),LPSS(a,start+1,end));
}
int LPSS_mem(string a,int start,int end,vector<vector<int>> &dp){
    if(start>end)return 0;
    if(start==end)return 1;
    if(dp[start][end]!=-1)return dp[start][end];
    if(a[start]==a[end]){
        int rem = end-start-1;
        if(LPSS_mem(a,start+1,end-1,dp)==rem)return dp[start][end]=rem+2; 
    }
    return dp[start][end]=max(LPSS_mem(a,start,end-1,dp),LPSS_mem(a,start+1,end,dp));
}

// Example Input
// A = "aaaabaaa"
// Example Output
// "aaabaaa"

int main(){
    // string s="aaaabaaa";
    // string s="abdbca";
    string s="abb";
    // string s="mmtatbdzqsoemuvnpppsu";

    dpArray dp;
    init_dp(dp,s.length(),s.length(),-1);
    // cout<<LPSS(s,0,s.length()-1)<<endl;
    // disp(dp);
    cout<<LPSS_mem(s,0,s.length()-1,dp)<<endl;
    disp(dp);
    return 0;
}