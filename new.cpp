#include <iostream>
using namespace std;
#include<string.h>

int main()
{
    int n;
    cin>>n;
    for(int i =1;i<=n;i++){
        string s=" ";
        for(int j=1;j<i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
