#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
bool canRepresentBST(vector<int>pre, int n){
    // Create an empty stack
    stack<int> s;
 
    // Initialize current root as minimum possible
    // value
    int root = INT_MIN;
 
    // Traverse given array
    for (int i=0; i<n; i++)
    {
        // If we find a node who is on right side
        // and smaller than root, return false
        if (pre[i] < root)
            return false;
 
        // If pre[i] is in right subtree of stack top,
        // Keep removing items smaller than pre[i]
        // and make the last removed item as new
        // root.
        while (!s.empty() && s.top()<pre[i])
        {
            root = s.top();
            s.pop();
        }
 
        // At this point either stack is empty or
        // pre[i] is smaller than root, push pre[i]
        s.push(pre[i]);
    }
    return true;
}

void convert(vector<int> pre,int low,int high){
    if(high==low){
        cout<<pre[low]<<" ";
        return;
    }
    int i=0,flag=0;
    for (i = low; i <=high; i++){
        if(pre[i]>pre[low]){
            flag=1;
            break;
        }
    }
    if(flag==0){
        for (int  j = high; j >=low; j--){
            cout<<pre[j]<<" ";
        }
        return ;
    }
    else{
        convert(pre,low+1,i-1);
        cout<<pre[low]<<" ";
        convert(pre,i,high);
    }
        
}
int main(){
    
    // vector<int> pre={10,7,5,1,8,13,12,15,14,18};
    vector<int> pre={7, 7, 10, 10, 9, 5, 2, 8};
    // vector<int> pre={30,20,10,15,25,23,39,35,42};
    // vector<int> pre={12,10,9,11,10,20,12,12};

    int n=pre.size();
    // convert(pre,0,n-1);
    // cout<<validate(pre,0,n);
    cout<<canRepresentBST(pre,n);
return 0;
}