#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// mode=l => left
// mode=r => right
void helper(vector<int>&vec, vector<int>&res,stack<int>&stk,int i){
    if(stk.empty())stk.push(i);
        else{
            while(!stk.empty() and vec[stk.top()]>=vec[i])stk.pop();
            res[i]=(stk.empty())?-1:stk.top();
            stk.push(i);
        }
}
vector<int> nearestSmaller(vector<int>&vec,char mode){
    int n=vec.size();
    vector<int> res(n,-1);
    stack<int> stk;
    if(mode=='l')for(int i = 0; i < n; i++)helper(vec,res,stk,i);
    else if(mode=='r')for (int i = n-1; i>=0; i--)helper(vec,res,stk,i);
    return res;
}
int LHA(vector<int> &vec){
    int n=vec.size();
    vector<int> left,right;
    left=nearestSmaller(vec,'l');
    right=nearestSmaller(vec,'r');
    int res=0;
    for(int i=0;i<n;i++){
        if(left[i]!=-1 and right[i]!=-1){
            res=max(res,(vec[i]*(right[i]-left[i]-1)));
        }
        else{
            res=max(res,vec[i]);
        }
    }
    return res;
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
 
int main(){

    vector<int> vec={2,1,5,6,2,3};
    cout<<LHA(vec);
    
    return 0;
}