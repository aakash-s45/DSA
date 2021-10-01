#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a,vector<int> b){
    return a[0]<b[0];
}
// 1 2 3
// void subset(vector<int> vec,int i,vector<vector<int>> &res,vector<int> node){
//     static int n=vec.size();
//     if(i>=n){
//         res.push_back(node);
//         return;
//     }

//     if(i<n){
//         subset(vec,i+1,res,node);
//         node.push_back(vec[i]);
//         subset(vec,i+1,res,node);
//     }  
// }

// void subset(vector<int>& vec,int j,vector<vector<int>> &res,vector<int> &node){
void subset(string &vec,int j,vector<string> &res,string &node){

    res.push_back(node);
    for (int i = j; i < vec.size(); i++){
        node.push_back(vec[i]);
        subset(vec,i+1,res,node);
        node.pop_back();        
    }
    return;
}

// void subset(string &vec,int j,vector<string> &res,string &node){

//     res.push_back(node);
//     for (int i = j; i < vec.size(); i++){
//         node.push_back(vec[i]);
//         subset(vec,i+1,res,node);
//         node.pop_back();        
//     }
//     return;
// }

// int rnkINd(string &vec,string x){

//     vector<string> res;
//     string node;
//     subset(vec,0,res,node);

//     res[0].push_back(0);
//     sort(res.begin(),res.end());
//     res[0].pop_back();
//     res.erase(res.begin());
//     for (int i = 0; i < res.size(); i++){
//         if(res[i]==x)return i+1;
//     }
    
//     return 0;
// }



//     // 1 2 3
//     // 
//     // 1
//     // 1 2
//     // 1 2 3
//     // 1 3
//     // 2
//     // 2 3
//     // 3


void disp(vector<string> vec){
    for(string a:vec){
        cout<<a<<" ";
    }
    cout<<endl;
}
// void disp(vector<vector<int>> vec){
//     for(vector<int> a:vec){
//         disp(a);
//     }
// }

int main(){
    // vector<int>vec={1,2,3};;
    string vec ="abc";
    // sort(vec.begin(),vec.end());
    // vector<vector<int>> res;
    vector<string> res;
    // vector<int> node;
    string node;

    subset(vec,0,res,node);

    res[0].push_back(0);
    sort(res.begin(),res.end());
    res[0].pop_back();
    
    disp(res);

    // string vec ="abc";
    // string x="ab";
    // return rnkINd(vec,"abc");

    return 0;
}