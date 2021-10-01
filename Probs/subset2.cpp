#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void subset(vector<int>& vec,int j,vector<vector<int>> &res,vector<int> &node){

    res.push_back(node);
    for (int i = j; i < vec.size(); i++){
        node.push_back(vec[i]);
        subset(vec,i+1,res,node);
        node.pop_back();        
    }
    return;
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
    vector<vector<int>> res;
    vector<int> node;
    // sort(A.begin(),A.end());
    subset(vec,0,res,node);
    disp(res);
    
    return 0;
}