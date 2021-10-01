#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int isRowValid(vector<string> vec,int row){
    unordered_set<char> st;
    for(int i=0;i<9;i++){
        if(st.find(vec[row][i])!=st.end())return false;
        if(vec[row][i]!='.')st.insert(vec[row][i]);
    }
    return true;
}
int isColValid(vector<string> vec,int col){
    unordered_set<char> st;
    for(int i=0;i<9;i++){
        if(st.find(vec[i][col])!=st.end())return false;
        if(vec[i][col]!='.')st.insert(vec[i][col]);
    }
    return true;
}
int isBoxValid(vector<string> vec,int row,int column){
    unordered_set<char> st;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(st.find(vec[i+row][j+column])!=st.end())return false;
            if(vec[i+row][j+column]!='.')st.insert(vec[i+row][j+column]); 
        }
    }
    return true;
}

int isValid(vector<string> vec){
    bool flag=true;
    for (int i = 0; i < 9; i++){
        flag=flag and isRowValid(vec,i);
    }
    for (int i = 0; i < 9; i++){
        flag=flag and isColValid(vec,i);
    }
    for (int i = 0; i < 9; i+=3){
        for (int j = 0; j < 9; j+=3){
            flag=flag and isBoxValid(vec,i,j);
        }
    }
    return flag; 
}



int main(){
    vector<string> vec={"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
    cout<<isValid(vec);

    return 0;
}