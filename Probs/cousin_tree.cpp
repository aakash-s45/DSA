#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

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

// bool path2(TreeNode* root,int val,vector<int> &vec){
//     if(root==NULL)return false;
//     vec.push_back(root->val);
//     if(root->val==val)return true;
//     if(path2(root->left,val,vec)||path2(root->right,val,vec))return true;
//     vec.pop_back();
//     return false;
// }

void path2(TreeNode* root,int val,vector<int>&vec,vector<vector<int>>&res){
    if(root==NULL || val<0)return;
    
    vec.push_back(root->val);
    val=val-root->val;
    if(val==0 and root->left==NULL and root->right==NULL)res.push_back(vec);
    path2(root->left,val,vec,res);
    path2(root->right,val,vec,res);
    vec.pop_back();
    return;
}

bool path(TreeNode* root,int val,vector<TreeNode*> &vec){
    if(root==NULL)return false;
    vec.push_back(root);

    if(root->val==val)return true;
    if(path(root->left,val,vec)||path(root->right,val,vec))return true;
    vec.pop_back();

    return false;
}
vector<int> levelOrder(TreeNode* root,int level,int sib1,int sib2){
    queue<TreeNode*> qu;
    qu.push(root);qu.push(NULL);
    vector<int> vec;
    int currLev=1;
    while(!qu.empty()){
        TreeNode*top=qu.front();
        qu.pop();
        if(top){
            if(currLev==level and (top->val!=sib1 and top->val!=sib2))vec.push_back(top->val);
            if(top->left)qu.push(top->left);
            if(top->right)qu.push(top->right);
        }
        else{
            if(!qu.empty())qu.push(NULL);
            currLev++;
        }
    }
    return vec;
}
vector<int> cousins(TreeNode* root,int val){
    vector<int> res;
    vector<TreeNode*> pathVec;
    cout<<"path 0"<<endl;
    if(!path(root,val,pathVec))return res;
    cout<<"path 1"<<endl;
    int pathSize=pathVec.size();
    int sib1=-2,sib2=-2;
    if(pathSize<3)return res;
    if(pathVec[pathSize-2]->left)sib1=pathVec[pathSize-2]->left->val;
    if(pathVec[pathSize-2]->right)sib2=pathVec[pathSize-2]->right->val;
    return levelOrder(root,pathVec.size(),sib1,sib2);
}

void preorder(TreeNode*root){
    if(root==nullptr)return;
    cout<<root->val<<", ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode*root){
    if(root==nullptr)return;
    inorder(root->left);
    cout<<root->val<<", ";
    inorder(root->right);
}


TreeNode* inorderPre(TreeNode* root){
    TreeNode* leftSubtree=root->left;
    while(leftSubtree->right!=nullptr){
        leftSubtree=leftSubtree->right;
    }
    return leftSubtree;
}


int main(){
    TreeNode * root= new TreeNode(1000);
    TreeNode * node1= new TreeNode(2000);
    TreeNode * node2= new TreeNode(-3000);
    root->left=node1;
    node1->left=node2;

    // TreeNode * node3= new TreeNode(11);
    // node1->left=node3;

    // TreeNode * node_4= new TreeNode(13);
    // TreeNode * node4= new TreeNode(4);
    // node2->left=node_4;
    // node2->right=node4;

    // TreeNode * node5= new TreeNode(7);
    // TreeNode * node6= new TreeNode(2);
    // node3->left=node5;
    // node3->right=node6;

    // TreeNode * node7= new TreeNode(5);
    // TreeNode * node8= new TreeNode(1);
    // node4->left=node7;
    // node4->right=node8;
    
    preorder(root);
    cout<<endl;

    int val=-1;
    vector<vector<int>> res;
    vector<int> vec1;

    path2(root,val,vec1,res);
    cout<<endl;
    disp(res);



    // path2(root,5,vec1);
    // disp(vec1);
    // cout<<endl;
    // disp(cousins(root,5));


    return 0;
}