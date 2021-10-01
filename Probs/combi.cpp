#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void combi(vector<int> &vec,int sum,vector<int> &node,vector<vector<int>> &res,int ind){
    
    if(sum==0){
        res.push_back(node);
    }
    for(int i=ind;i<vec.size();i++){
        if(i!=ind and vec[i]==vec[i-1])continue;
        if(!node.empty() and node.back()>vec[i])continue;
        node.push_back(vec[i]);
        combi(vec,sum-vec[i],node,res,ind+1);
        node.pop_back();
    }
    
}
void disp(vector<int> vec){
    for(int a:vec){
        cout<<a<<' ';
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
    // vector<vector<int>> dp;
    // vector<int> vec={1,2,2};
    vector<int> vec={10,1,2,7,6,1,5};
    sort(vec.begin(),vec.end());
    vector<int> node;
    vector<vector<int>> res;
    int sum=8;
    combi(vec,sum,node,res,0);
    disp(res);
    return 0;
}