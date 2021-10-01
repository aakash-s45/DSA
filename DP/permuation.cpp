#include <bits/stdc++.h>
using namespace std;

//            123
//          /  |  \
//     123   |213|  312       now first elem is fixed
//  /   |     /  \    |   \
//123|132  213 | 231  312 | 321  now first 2 are fixed

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
        cout<<a<<" ";
    }
    cout<<endl;
}
void disp(vector<vector<int>> vec){
    for(vector<int> a:vec){
        disp(a);
    }
}
int main()
{
    vector<int> vec={1,2,3};
    vector<vector<int>> res;
    int n=vec.size();
    permuation(vec,0,n-1,res);
    disp(res);
    return 0;
}