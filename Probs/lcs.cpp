#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
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

int perfectPeak(vector<int> &A) {

    int n=A.size();
    vector<int> suffixMAx;
    int maxe=INT_MIN;
    for(int i=n-1;i>0;i++){
        maxe=max(maxe,A[i]);
        suffixMAx.push_back(maxe);
    }
    suffixMAx.pop_back();
    int mini=A[0];
    for(int i=1;i<A.size()-1;i++){
        if(!suffixMAx.empty() and A[i]>mini and suffixMAx.back()>A[i]){
            return 1;
        }
        else if(!suffixMAx.empty()){
            mini=min(A[i],mini);
            suffixMAx.pop_back();
        }
    }
    return 0;
}



 
int main(){
    vector<int> vec={ 5706, 26963, 24465, 29359, 16828, 26501, 28146, 18468, 9962, 2996, 492, 11479, 23282, 19170, 15725, 6335};
    disp(vec);
    cout<<endl;
    cout<<perfectPeak(vec);
    return 0;
}