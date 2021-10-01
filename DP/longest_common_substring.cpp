#include "DP.h"


int LCS_dp(string a,string b){
    int m=a.length(),n=b.length();
    cout<<m<<endl;
    dpArray dp;
    init_dp(dp,m,n,0);
    int val=INT_MIN;
    int xIdx=0;
    int yIdx=0;
    for(int i=1;i<m+1;i++){
        for (int j = 1; j < n+1; j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=0;
            // val=max(val,dp[i][j]);

            if(dp[i][j]>val){
                val=dp[i][j];
                xIdx=i;
                yIdx=j;
            }
        }
    }
    int i=xIdx,j=yIdx;
    string res;
    string temp;
    disp(dp);
    while(i>0 and j>0){
        if(temp.length()>res.length())res=temp;
        if(dp[i][j]==0)temp.clear();
        temp.push_back(a[i-1]);
        i--;
        j--;
    }
    if(temp.length()>res.length())res=temp;

    while(i>0){
        if(dp[i][j]==0)temp.clear();
        if(temp.length()>res.length())res=temp;
        temp.push_back(a[i-1]);
        i--;
    }
    while(j>0){
        if(dp[i][j]==0)temp.clear();
        if(temp.length()>res.length())res=temp;
        temp.push_back(a[i-1]);
        j--;
    }
    cout<<res<<endl;
    cout<<xIdx<<" "<<yIdx<<endl;
    cout<<endl;
    return val;

}
// int LCS_dp(string a,string b){
//     int m=a.length(),n=b.length();
//     dpArray dp;
//     init_dp(dp,m,n,0);
//     int val=INT_MIN;
//     for(int i=1;i<m+1;i++){
//         for (int j = 1; j < n+1; j++){
//             if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
//             else dp[i][j]=0;
//             val=max(val,dp[i][j]);
//         }
//     }

    
//     disp(dp);
//     // return dp[m][n];
//     return val;

// }

bool ispalin(string &A){
    int i=0;
    int j=A.length()-1;
    while(i<=j){
        if(A[i]!=A[j])return false;
        i++;
        j--;
    }
    return true;
}
 
int main(){
    // string a="caccbcbaabacabaccacaaccaccaaccbbcbcbbaacabccbcccbbacbbacbccaccaacaccbbcc";
    // string a="banana";
    // string a="AACECAAAA";
    string a="mmtatbdzqsoemuvnpppsu";
    // string a="babb";
    // string a="apple";
    string b=a;
    reverse(b.begin(),b.end());
    cout<<a<<endl;
    cout<<b<<endl;
    int m=a.length();
    int n=b.length();
    dpArray dp;
    init_dp(dp,m,n,-1);
    cout<<LCS_dp(a,b)<<endl;
    // int result=INT_MIN;
    // // cout<<lcs(a,b,m,n,result,dp)<<endl;
    // cout<<result<<endl;
    

    return 0;
}