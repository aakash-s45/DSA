#include <bits/stdc++.h>
using namespace std;

void teelphone(vector<string> vec,int k,vector<string> &res,string node){

    if(node.size()==vec.size())res.push_back(node);
    for (int i = k; i < vec.size(); i++){
        if(node.size()==k and i>k)return;
        for (int j = 0; j < vec[i].length(); j++){
            node.push_back(vec[i][j]);
            teelphone(vec,k+1,res,node);
            node.pop_back();
        } 
    }
    return;
    
}


vector<string> solver(string s){
    vector<string> phone={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> vec;
    vector<string>res;
    string node;
    for(int i=0;i<s.length();i++){
        vec.push_back(phone[s[i]-'0']);
    }
    teelphone(vec,0,res,node);
    return res;  
}



void disp(vector<string> vec){
    for(string a:vec){
        cout<<a<<" ";
    }
    cout<<endl;
}
// void disp(vector<vector<char>> vec){
//     for(vector<char> a:vec){
//         disp(a);
//     }
// }

int main()
{
    
    string s="2";
    vector<string>res;
    res=solver(s);
    disp(res);

    return 0;
}