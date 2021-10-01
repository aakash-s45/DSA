#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isplain(string &s){
    int i=0;
    int j=s.length()-1;
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++,j--;
    }
    return true;
}
//fully optimised code to print longest palindrome substring
string LPSS_print(string &s){
    if(isplain(s))return s;
    int n=s.length();

    string res;
    int maxlen=1;
    int first=0;
    // for every element we are checking which palindrome we can make by taking i-th index as center
    for(int i=1;i<n-1;i++){
        // odd length palindrome
        int center=i;
        int left=i-1,right=i+1;
        int templen=1;
        while(left>=0 and right<n){
            if(s[left]==s[right]){
                templen+=2;
                left--;
                right++;
            }
            else break;
        }
        if(maxlen<templen){
            maxlen=templen;
            first=++left;
        }
        // even length palindrome
        left=i;
        right=i+1;
        templen=0;
        while(left>=0 and right<n){
            if(s[left]==s[right]){
                templen+=2;
                left--;
                right++;
            }
            else break;
        }
        if(maxlen<templen){
            maxlen=templen;
            first=++left;
        }
    }

    for(int i=first;i<first+maxlen;i++){
       res.push_back(s[i]); 
    }
    return res;
}
 
int main(){
    string s="cccb";
    // string s="abdbca";
    cout<<LPSS_print(s);

    return 0;
}