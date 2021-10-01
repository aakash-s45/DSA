#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
vector<int> adjList[100];
bool visited[100];
/*
7 inputs

1 2
1 3
2 4
2 5
2 6
2 7
7 3

*/

void dfs(int node){
    visited[node]=true;
    cout<<node<<", ";
    for(int i:adjList[node]){
        if(visited[i]);
        else dfs(i);
    }
}

int main(){
    int n=7;

    for (int i = 0; i < n; i++){
        visited[i]=false;
    }

    int edg1,edg2;

    for (int i = 0; i < n; i++){
        cin>>edg1>>edg2;
        // for undirected graph
        adjList[edg1].push_back(edg2);
        adjList[edg2].push_back(edg1);
    }
    dfs(1);

    
    return 0;
}