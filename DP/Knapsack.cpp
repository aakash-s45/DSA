#include <bits/stdc++.h>
using namespace std;


int knapsack(vector<int> weight,vector<int> value,int n,int w){
    if(n==0 || w==0)return 0;
    if(weight[n-1]<=w){
        return max((value[n-1]+knapsack(weight,value,n-1,w-weight[n-1])),(knapsack(weight,value,n-1,w)));
    }
    else{
        return knapsack(weight,value,n-1,w);
    }
}
int knapsack_mem(vector<int> weight,vector<int> value,int n,int w,vector<vector<int>>dp){
    if(n==0 || w==0)return 0;
    if(dp[n][w]!=-1)return dp[n][w];
    if(weight[n-1]<=w){
        return dp[n][w]=max((value[n-1]+knapsack_mem(weight,value,n-1,w-weight[n-1],dp)),(knapsack_mem(weight,value,n-1,w,dp)));
    }
    else{
        return dp[n][w]=knapsack_mem(weight,value,n-1,w,dp);
    }
}
int knapsack_dp(vector<int> weight,vector<int> value,int w, vector<vector<int>> dp){
    int n=weight.size();
    // initialization
    for (int i = 0; i <n+1; i++){
        for (int j = 0; j < w+1; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    // answer
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < w+1; j++){
            //  now i is the size of array and j is the weight ( sub problem)
            if(weight[i-1]<=j){
                // whether we take the last value of the array or not
                dp[i][j]=max((value[i-1]+dp[i-1][j-weight[i-1]]),(dp[i-1][j]));
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        } 
    }
    return dp[n][w];
}

void disp(vector<int> vec){
    for(int a:vec){
        cout<<a<<" ";
    }
    cout<<endl;
}
void disp(vector<vector<int>> vec){
    for(vector<int> a:vec){
        disp(a);
    }
}

void init_dp(vector<vector<int>>&dp,int n,int w,int val){
    for (int i = 0; i <n+1; i++){
       vector<int> node(w+1,val);
       dp.push_back(node); 
    }
}

int main(){

    vector<int> weight={1,9,7,6,4,3,85,74,12,96,74};
    vector<int> value={10,14,100,45,90,20,85,74,12,96,74};
    int w=31;
    int n=weight.size();

    vector<vector<int>>stor;
    init_dp(stor,n,w,-1);
    cout<<knapsack(weight,value,n,w)<<endl;
    cout<<knapsack_mem(weight,value,n,w,stor)<<endl;


    vector<vector<int>>dp;
    init_dp(dp,n,w,0);

    cout<<knapsack_dp(weight,value,w,dp);
    return 0;
}