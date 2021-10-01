#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void permuation(vector<int> &vec,int low,int high,vector<vector<int>> &res){
    if(low==high){
        res.push_back(vec);
        return;
    }
    // every time we are fixing first character and swap others with the second element
    for(int i=low;i<=high;i++){
        swap(vec[low],vec[i]);
        permuation(vec,low+1,high,res);
        swap(vec[low],vec[i]);
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
    vector<int> vec={1,2,3};
    vector<vector<int>> res;
    permuation(vec,0,vec.size()-1,res);
    disp(res);

    
    return 0;
}