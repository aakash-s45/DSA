#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 

vector<int> solve(vector<int> &A, int B) {
    int n=A.size();
    vector<int> ind(n,0);
    for(int i=0;i<n;i++){
        ind[A[i]-1]=i;
    }
    int i=0;
    int k=B;
    while(k and i<n){
        if(A[i]==(n-i)){
            i++;
        }
        else if(k--){
            int val=n-i;
            int curr=A[i];
            swap(A[i],A[ind[val-1]]);
            swap(ind[val-1],ind[curr-1]);
        }
    }
    return A;
}

void disp(vector<int> vec){
    for(int a:vec){
        cout<<a<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> vec={3,2,4,1,5};
    vector<int> res;
    res=solve(vec,3);
    disp(res);

return 0;
}