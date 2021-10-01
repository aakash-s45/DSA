#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void subset(vector<int> &vec,int sum,vector<int> &node,vector<vector<int>> &res,int ind){
    
    if(ind==vec.size())return;
    res.push_back(node);
    for(int i=ind;i<vec.size();i++){

        if(i!=ind and vec[i]==vec[i-1])continue;

        node.push_back(vec[i]);
        subset(vec,sum-vec[i],node,res,i+1);
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


int main(){
    vector<int> vec={1,2,2};
    // vector<int> vec={10,1,2,7,6,1,5};
    sort(vec.begin(),vec.end());
    vector<int> node;
    vector<vector<int>> res;
    int sum=8;
    subset(vec,sum,node,res,0);
    disp(res);
    
    return 0;
}