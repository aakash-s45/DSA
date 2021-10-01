#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isPalin(string &s,int low,int high){
    while(low<=high){
        if(s[low]!=s[high])return false;
        low++,high--;
    }
    return true;
}
vector<string> res;
int PP(string &s,int i,int j){
    // find i and j
    // base conditon
    // k in loop
    // function
    // answer
    // for ex. aab
    if(i>=j)return 0;
    if(isPalin(s,i,j)){
        string an;
        while(i<=j){
            an.push_back(s[i]);
            i++;
        }
        res.push_back(an);
        return 0;
    }
    int mini=INT_MAX;
    for (int k = i; k <=j-1; k++){
        int temp=0;
        temp=1+PP(s,i,k)+PP(s,k+1,j);
        mini=min(mini,temp);
    }
    return mini; 
}

void disp(vector<string>& vec){
    for(string a:vec){
        cout<<a<<' ';
    }
    cout<<endl;
}

int main(){
    string s="assd";
    cout<<PP(s,0,s.length()-1)<<endl;
    disp(res);
    return 0;
}