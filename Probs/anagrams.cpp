#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 

vector<vector<int>> anagrams(const vector<string> &A) {
    map<int,vector<int>> mp;
    
    for(int i=0;i<A.size();i++){
        
    }
    for(int i=0;i<A.size();i++){
        int sum=0;
        for(int j=0;j<A[i].length();j++){
            sum+=A[i][j];
        }
        
        if(mp.find(sum)==mp.end()){
            vector<int> node;
            node.push_back(i+1);
            mp.insert(make_pair(sum,node));
        }
        else{
            mp[sum].push_back(i+1);
        }
    }
    vector<vector<int>> res;
    for(auto i:mp){
        res.push_back(i.second);
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

    vector<string> vec={"cat","dog","god","tca"};
    vector<vector<int>> res;
    res=anagrams(vec);
    disp(res);
    return 0;
}