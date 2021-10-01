#include <bits/stdc++.h>
using namespace std;


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


int SubsetSum(vector<int> vec,int sum,vector<vector<int>>&dp){
    int n=vec.size();
    for (int i = 0; i < sum+1; i++){
        dp[0][i]=0;
    }
    for (int i = 0; i < n+1; i++){
        dp[i][0]=1;
    }
    disp(dp);
    cout<<endl;
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < sum+1; j++){
            if(vec[i-1]<=j){
                dp[i][j]=dp[i-1][j-vec[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
        
    }
    disp(dp);
    cout<<endl;
    return dp[n][sum];
}
void init_dp(vector<vector<int>>&dp,int n,int w,int val){
    for (int i = 0; i <n+1; i++){
       vector<int> node(w+1,val);
       dp.push_back(node); 
    }
}

int targetsum(vector<int>vec,int target,vector<vector<int>>&dp){
    int range=0;
    int n=vec.size();
    for (int i = 0; i < vec.size(); i++){
        range+=vec[i];
    }
    // if(target == 0 or target==range)return 1;
    // S1-S1=target
    // S1+S2=Sum
    // 2S1=target+sum
    // S1=(target+sum)/2
    // search for a subset with sum = (target+sum)/2
    int final_Traget=(target+range);
    if(final_Traget%2)return 0;
    final_Traget/=2;
    init_dp(dp,n,final_Traget,0);
    return SubsetSum(vec,final_Traget,dp);
}

int main(){
    vector<int>vec={1,1,2,3};
    int target=1;
    int n=vec.size();
    vector<vector<int>>dp;
    cout<<targetsum(vec,target,dp);


    return 0;
}

