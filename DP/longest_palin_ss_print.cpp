#include "DP.h"

/*
a bbsbb d
a bbsbb
*/
struct node{
    int first;
    int last;
    int length;
};


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
// int LPSS_mem(string a,int start,int end,vector<vector<int>> &dp){
//     if(start>end)return 0;
//     if(start==end)return 1;
//     if(dp[start][end]!=-1)return dp[start][end];
//     if(a[start]==a[end]){
//         int rem = end-start-1;
//         if(LPSS_mem(a,start+1,end-1,dp)==rem)return dp[start][end]=rem+2; 
//     }
//     return dp[start][end]=max(LPSS_mem(a,start,end-1,dp),LPSS_mem(a,start+1,end,dp));
// }

string LPS_print(string s){
    int n=s.length();
    bool dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    int maxlen=1;
    int first_idx=0;
    //initialize for 1 lenght ss
    for (int i = 0; i < n+1; i++){
        dp[i][i]=true;
    }
    //initialize for 2 lenght
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=true;
            maxlen=2;
            first_idx=i;
        }
    }
    // now check for more lenght ss
    for (int len = 3; len < n; len++){
        for (int start = 0; start < n-len+1; start++){
            int end=start+len-1;
            if(s[start]==s[end] and dp[start+1][end-1]){
                dp[start][end]=true;
                if(len>maxlen){
                    maxlen=len;
                    first_idx=start;
                }
            }
        }
    }
    string res;
    for(int i=first_idx;i<first_idx+maxlen;i++){
        res.push_back(s[i]);
    }
    return res;
    
}

// int frst=-1;
// int LPSS_mem(string a,int start,int end,vector<vector<int>> &dp){
//     if(start>end)return 0;
//     if(start==end)return 1;
//     if(dp[start][end]!=-1)return dp[start][end];
//     if(a[start]==a[end]){
        
//         int rem = end-start-1;
//         int valf=LPSS_mem(a,start+1,end-1,dp);
//         if(valf==rem){
//             if(frst==-1)frst=start;
//             return dp[start][end]=rem+2;
//         } 
//     }
//     frst=-1;
//     return dp[start][end]=max(LPSS_mem(a,start,end-1,dp),LPSS_mem(a,start+1,end,dp));
// }

int frst = -1;
int len = 0;
int LPSS_mem(string a, int start, int end, vector<vector<int>>& dp) {
    if (start > end)return 0;
    if (start == end)return 1;
    if (dp[start][end] != -1)return dp[start][end];
    if (a[start] == a[end]) {
    //    if (frst == -1)frst = start;
        int rem = end - start - 1;
        if (LPSS_mem(a, start + 1, end - 1, dp) == rem) {
            if (end - start + 1 > len) {
                len = end - start + 1;
                frst = start;
            }
            return dp[start][end] = rem + 2;
        }
    }
    return dp[start][end] = max(LPSS_mem(a, start, end - 1, dp), LPSS_mem(a, start + 1, end, dp));
}
string solve(string &s){
    vector<vector<int>> dp;
    init_dp(dp,s.length(),s.length(),-1);
    int len=LPSS_mem(s,0,s.length()-1,dp);
    string res;
    for (int i = frst; i < len+frst; i++){
        res.push_back(s[i]);   
    }
    return res;
}

int main(){
    string s="abacdfgdcaba";
    // string s="aaaabaaa";
    // string s="abdbca";
    // string s="mmtatbdzqsoemuvnpppsu";
    // dpArray dp;
    // init_dp(dp,s.length(),s.length(),-1);
    // cout<<LPSS_mem(s,0,s.length()-1,dp)<<endl;
    // cout<<"starts at: "<<frst<<endl;
    // cout<<LPS_print(s);
    cout<<solve(s);
    return 0;
}