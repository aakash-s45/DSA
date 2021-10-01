#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

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
void postorder(TreeNode*root){
    if(root==nullptr)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<", ";
}


TreeNode* create(vector<int> &pre,vector<int> &ino,int rootIdx,int start,int end){
    if(start>end)return nullptr;
    // if(start==end){
    //     TreeNode* root=new TreeNode(pre[rootIdx]);
    //     return root;
    // }

    int idx;
    for(int i=start;i<=end;i++){
        if(ino[i]==pre[rootIdx]){
            idx=i;
            break;
        }
    }
    TreeNode* root=new TreeNode(pre[rootIdx]);
    root->left=create(pre,ino,rootIdx+1,start,idx-1);
    root->right=create(pre,ino,rootIdx+idx-start+1,idx+1,end);
    return root;
}

TreeNode* create_in_post(vector<int> &post,vector<int> &ino,int rootIdx,int start,int end){
    if(start>end)return nullptr;

    int idx;
    for(int i=end;i>=start;i--){
        if(ino[i]==post[rootIdx]){
            idx=i;
            break;
        }
    }
    TreeNode* root=new TreeNode(post[rootIdx]);
    root->right=create_in_post(post,ino,rootIdx-1,idx+1,end);
    root->left=create_in_post(post,ino,rootIdx-end+idx-1,start,idx-1);
    return root;
}

int main(){
    vector<int> pre={8,3,1,6,4,7,10,14,13};
    vector<int> post={1,4,7,6,3,13,14,10,8};
    vector<int> ino={1,3,4,6,7,8,10,13,14};

    TreeNode *root=nullptr;
    // int rootIdx=0;
    // root=create(pre,ino,rootIdx,0,pre.size()-1);
    // preorder(root);

    int rootIdx=ino.size()-1;
    root=create_in_post(post,ino,rootIdx,0,rootIdx);
    cout<<endl;
    inorder(root);

    return 0;
}