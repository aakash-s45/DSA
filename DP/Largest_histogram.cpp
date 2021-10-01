#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &A) {
    int n=A.size();
    int res=0;int i=0;
    stack<int> stk;
    while(i<n){
        // maintain the stack in increasing order
        // if we encounter an element which is graeter than top of the stack then we have to
        // pop the stack until we get a smaller element and then find the area 
        while(!stk.empty() and A[stk.top()]>A[i]){
            int tp=stk.top();
            int minhight=A[tp];
            stk.pop();
            if(stk.empty()){
                res=max(res,(minhight*i));
            }
            else{
                int width=i-stk.top()-1;
                res=max(res,minhight*width);
            }
        }
        stk.push(i);
        i++;
    }
    return res;

}


int main()
{
    vector<int> vec={6, 2, 5, 4, 5, 1, 6};
    cout<<largestRectangleArea(vec);
    return 0;
}