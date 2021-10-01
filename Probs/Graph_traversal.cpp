#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:

    map<int,vector<int>> adj;
    unordered_set<int> visited;

    Graph();
    void addEgde(int ,int );
    void addD_Egde(int ,int );
    void dfs(int);
    void bfs(int);
};
Graph::Graph(){
    adj.clear();
    visited.clear();
}
// undirected edge
void Graph::addEgde(int node1,int node2){
    // for undirected
    adj[node1].push_back(node2);
    adj[node2].push_back(node1);
}
// directed edge :: node->node2
void Graph::addD_Egde(int node1,int node2){
    adj[node1].push_back(node2);
}
void Graph::dfs(int node){
    visited.insert(node);
    cout<<node<<" ";
    for(int i:adj[node]){
        if(visited.find(i)==visited.end())dfs(i);
    }
}
void Graph::bfs(int node){
    visited.clear();
    queue<int> qu;
    qu.push(node);

    while (!qu.empty()){
        int temp=qu.front();
        qu.pop();
        if(visited.find(temp)==visited.end()){
            visited.insert(temp);
            cout<<temp<<" ";
            for(int i:adj[temp]){
                qu.push(i);
            }
        } 
    }
    visited.clear();
}
 
int main(){
    Graph g;
    // g.addEgde(1,2);
    // g.addEgde(1,3);
    // g.addEgde(2,4);
    // g.addEgde(2,5);
    // g.addEgde(2,6);
    // g.addEgde(2,7);
    // g.addEgde(7,3);
    g.addEgde(1,2);
    g.addEgde(1,4);
    g.addEgde(2,3);
    g.addEgde(4,3);
    g.addEgde(3,5);
    g.addEgde(5,6);
    g.addEgde(5,7);

    g.dfs(1);
    cout<<endl;
    g.bfs(1);
    
    return 0;
}