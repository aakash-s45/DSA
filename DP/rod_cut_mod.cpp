#include "DP.h"

// int RodCutting(vec lenArr,vec costArr,int RodLength){
//     vector<vec> dp;
//     int n=lenArr.size();
//     init_dp(dp,n,RodLength,0);
    
//     f(i,1,n+1){
//         f(j,1,RodLength+1){
//             if(j>=lenArr[i-1]){
//                 dp[i][j]=max(costArr[i-1]+dp[i][j-lenArr[i-1]], dp[i-1][j]);
//             }
//             else dp[i][j]=dp[i-1][j];
//         }
//     }
//     return dp[n][RodLength];
// }




int main(){

    vector<vector<int>> dp;
    for(int i=0;i<=n;i++){
        vector<int> node(n+1,-1);
        dp.push_back(node);
    }
    return 0;
}