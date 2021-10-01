#include <bits/stdc++.h>
using namespace std;

// A:bigger string
// B:smaller string
// mode:1 reverse enable
// mode:0 disable
string add(string a,string b,int mode=1){
    string c;
    if(a.length()<b.length())return c=add(b,a,mode);
    if(mode){
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
    }

    int carry=0;
    int val;
    for (int i = 0; i < b.length(); i++){
        val=((b[i]-'0')+(a[i]-'0')+carry)%10;
        carry=((b[i]-'0')+(a[i]-'0')+carry)/10;
        c.push_back(val+'0');
    }
    if(b.length()<a.length()){
        for (int i = b.length(); i < a.length(); i++){
            val=(carry+(a[i]-'0'))%10;
            carry=(carry+(a[i]-'0'))/10;
            c.push_back(val+'0');
        }
        if(carry!=0)c.push_back(carry+'0');
        
    }
    else if(carry!=0)c.push_back(carry+'0');
    if(mode)reverse(c.begin(),c.end());
    return c;
}

string multiply(string a,char c){
    string res;
    int num=(c-'0');
    int carry=0;
    int val;
    for (int i = 0; i < a.length(); i++){
        val=((a[i]-'0')*num+carry)%10;
        carry=((a[i]-'0')*num+carry)/10;
        res.push_back(val+'0');
    }
    if(carry!=0)res.push_back(carry+'0');
    return res;
}

string multiply(string a,string b){
    string c;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string first=multiply(a,b[0]);
    string zero="0";
    string temp;
    for(int i=1;i<b.length();i++){
        temp=multiply(a,b[i]);
        temp=zero+temp;
        first=add(first,temp,0);
        zero.push_back('0');
    }
    reverse(first.begin(),first.end());
    return first;
}

string facto(int n){
    string res="1";
    for(int i=n;i>=1;i--){
        res=multiply(res,to_string(i));
    }
    return res;
}

int main(){
    // cout<<add("38796408","307908000");
    // cout<<multiply("123",'3');
    // cout<<multiply("51318","56675");
    // cout<<multiply("51318","566756");
    // cout<<multiply("51318",'6');
    // cout<<multiply("81315",'6');
    // 290 847 84408
    // 290 746 84408
    // 521
    // 005
    // 526
    string s=facto(100);
    cout<<s<<endl;
    int count=0;
    
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]!='0')break;
        else count++;
    }
    cout<<count<<endl;
    return 0;
}