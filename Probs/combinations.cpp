#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// If n = 4 and k = 2, a solution is:

// [
//   [1,2],
//   [1,3],
//   [1,4],
//   [2,3],
//   [2,4],
//   [3,4],
// ]


// 1 2 3
// 1 2 4
// 1 3 4
// 2 3 4
int countCalls=0;

void combination(int n,int k,int start,vector<int> &node,vector<vector<int>>&res){
    countCalls++;
    if(k==0 ){
        res.push_back(node);
        return;
    }
    for(int i=start;i<=n-k+1;i++){
        node.push_back(i);
        combination(n,k-1,i+1,node,res);
        node.pop_back();
    }
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



int main(){
    vector<int> node;
    vector<vector<int>> res;
    combination(5,3,1,node,res);
    disp(res);
    cout<<endl;
    cout<<countCalls<<endl;

    return 0;
}