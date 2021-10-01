#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> dpArray;

// dp-> DP array
// n-> no. of rows
// m-> no. of columns
// val-> Value to initialize with
void init_dp(vector<vector<int>>&dp,int n,int w,int val){
    for (int i = 0; i <n+1; i++){
       vector<int> node(w+1,val);
       dp.push_back(node); 
    }
}
void reinit_dp(vector<vector<int>>&dp,int val){
    for(int i=0; i<dp.size();i++){
        for (int j = 0; j < dp[0].size(); j++){
            dp[i][j]=val;
        }
        
    }
}

// void disp(vector<int> vec){
//     for(int a:vec){
//         cout<<a<<" ";
//     }
//     cout<<endl;
// }
void disp(vector<int> vec){
    for(int a:vec){
        if(a!=-1)cout<<' '<<a<<" ";
        else cout<<a<<" ";
    }
    cout<<endl;
}
void disp(vector<vector<int>> vec){
    for(vector<int> a:vec){
        disp(a);
    }
}