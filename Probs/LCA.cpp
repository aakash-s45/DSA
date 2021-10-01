#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

void preorder(TreeNode*root){
    if(root==nullptr)return;
    preorder(root->left);
    cout<<root->val<<", ";
    preorder(root->right);
}

void disp(vector<int> vec){
    for(int a:vec){
        cout<<a<<' ';
    }
    cout<<endl;
}
void disp(vector<vector<int>> vec){
    for(vector<int> a:vec){
        disp(a);
    }
}
bool getpath(TreeNode*root,int node1,vector<int>&path1){
    if(root==nullptr)return false;

    path1.push_back(root->val);
    if(root->val==node1){
        return true;
    }
    if(getpath(root->left,node1,path1))return true;
    if(getpath(root->right,node1,path1))return true;
    path1.pop_back();
    return false;
}

int ancester(TreeNode* root,int node1,int node2){
    vector<int> path1,path2;
    if(!getpath(root,node1,path1) || !getpath(root,node2,path2))return -1;
    int i=0,j=0;
    int ans=path1[0];
    while(i<path1.size() and j<path2.size() and path1[i]==path2[j]){
        ans=path1[i];
        i++,j++;
    }
    return ans;
}
 

vector<int> diagonal_traversal(TreeNode* root){
    vector<int> res;
    queue<TreeNode*> qu;
    TreeNode* curr=root;
    while(curr!=nullptr || !qu.empty()){
        if(curr){
            res.push_back(curr->val);
            if(curr->left!=nullptr)qu.push(curr->left);
            curr=curr->right;
        }
        else{
            curr=qu.front();
            qu.pop();
        }
        
    }
    return res;
}
int main(){
    TreeNode * root= new TreeNode(4);
    TreeNode * node1= new TreeNode(6);
    TreeNode * node2= new TreeNode(2);
    TreeNode * node3= new TreeNode(3);
    TreeNode * node4= new TreeNode(5);
    TreeNode * node5= new TreeNode(1);
    TreeNode * node6= new TreeNode(7);
/*
             4
        2         6
    1       3 5        7
*/
    
    root->left=node2;
    root->right=node1;

    node2->left=node5;
    node2->right=node3;

    node1->left=node4;
    node1->right=node6;

    preorder(root);
    cout<<endl;
    cout<<"a   "<<endl;
    // vector<int> path;
    // getpath(root,3,path);
    // disp(path);
    // cout<<ancester(root,3,7);
    disp(diagonal_traversal(root));
    
    return 0;
}