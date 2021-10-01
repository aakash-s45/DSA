#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int minIdx(vector<int> vec){
    int n=vec.size();
    int start=0,end=n-1;
    while(start<end){
        int mid=start+(end-start)/2;
        int prev=(mid+n-1)%n;
        int next=(mid+1)%n;
        if(vec[mid]<=vec[next] and vec[mid]<=vec[prev])return mid;
        else if(vec[mid]<=vec[end]){
            end=prev;
        }
        else{
        // else if(vec[start]<=vec[mid]){
            start=next;
        }
    }
    return -1;
}

int binary_search(vector<int> vec,int start,int end,int val){
    while(start<=end){
        int mid=start+(end-start)/2;

        if(vec[mid]==val)return mid;
        else if(vec[mid]>val){
            end=mid-1;
        }
        else start=mid+1;
    }
    return -1;
}
 
int main(){
    // vector<int> vec={4,7,9,11,15,22,1,3};
    vector<int> vec={1, 7, 67, 133, 178};
    int idx=minIdx(vec);
    cout<<idx<<endl;
    int B=1;
    // int one =binary_search(vec,0,idx-1,B);
    // int two =binary_search(vec,idx,vec.size()-1,B);
    // if(one!=-1 and two==-1)cout<<one;
    // if(one!=-1 and two!=-1)cout<< -1;
    // if(one==-1 and two!=-1)cout<< one;
    return 0;
}