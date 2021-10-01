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

/*
2908510 270819850789559186272617516888327423123873148888424607118651485509659124827305707500313046783445 64428861596637320
2908510 270819850789559186272617516888327423123873148888424607118651485509659124827305707500313046783445 64428861596637320
2908510 169799840668356953247604384887194201891420676646121385098117164167547022816084597180192046482344 64426861596637320
2908510 169799840668356953247604384887194201891420676646121385098117164167547022816084597180192046482344 64426861596637320
*/

int main(){
    // cout<<add("38796408","307908000");
    // cout<<multiply("123",'3');
    cout<<multiply("51318","56675");
    // cout<<multiply("51318","566756");
    // cout<<multiply("51318",'6');
    // cout<<multiply("81315",'6');
    // 290 847 84408
    // 290 746 84408
    // 521
    // 005
    // 526
    return 0;
}