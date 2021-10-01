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


int searchNode(TreeNode* root,int key){
    TreeNode*temp=root;
    while (temp!=nullptr){
        if(temp->val==key)return key;
        else if(temp->val>key)temp=temp->left;
        else if(temp->val<key)temp=temp->right;
    }
    return -1; 
}
void insertNode(TreeNode* root, int key){
    /* Find the place at which we insert the node and then insert it*/
    TreeNode* prev=nullptr;
    TreeNode* ptr=root;
    while(ptr!=nullptr){
        prev=ptr;
        if(ptr->val==key)return;
        else if(ptr->val>key)ptr=ptr->left;
        else if(ptr->val<key)ptr=ptr->right;
    }
    TreeNode * newNode=new TreeNode(key);
    if(key>prev->val)prev->right=newNode;
    else prev->left=newNode;

}

TreeNode* inorderPre(TreeNode* root){
    TreeNode* leftSubtree=root->left;
    while(leftSubtree->right!=nullptr){
        leftSubtree=leftSubtree->right;
    }
    return leftSubtree;
}

TreeNode* deleteNode(TreeNode* root,int key){

    if(root==nullptr)return root;
    // if the node is a leaf node remove it(base case)
    if(root->left==nullptr and root->right==nullptr){
        free(root);
        return nullptr;
    }
    // search the node
    if(key<root->val)root->left=deleteNode(root->left,key);
    else if(key>root->val)root->right=deleteNode(root->right,key);
    // now delete the node
    else{
        TreeNode* inPre=inorderPre(root);
        root->val=inPre->val;
        // INpre lies in left subtree so now we have to delete the inpre
        root->left = deleteNode(root->left,inPre->val);
    }
    return root;
}

TreeNode* solve(TreeNode* root){
    if(root==NULL)return root;
    
    if(root->left!=NULL and root->right!=NULL){
        root->left=solve(root->left);
        root->right=solve(root->right);
        return root;
    }
    if(root->left==NULL and root->right==NULL)return root;
    if(root->right==NULL)return root->left;
    if(root->left==NULL)return root->right;
    return root;
}
TreeNode* solve2(TreeNode* root){
    if(root==NULL)return nullptr;

    root->left=solve2(root->left);
    root->right=solve2(root->right);
    
    if(root->left==NULL and root->right==NULL)return root;

    if(root->left==NULL){
        TreeNode* temp=root->right;
        free(root);
        return temp;
    }
    if(root->right==NULL){
        TreeNode* temp=root->left;
        free(root);
        return temp;
    }
    return root;
}

/*
            1
          /   \
         2     3
        / \     \
       4   5     6
*/
int main(){
    // TreeNode * root= new TreeNode(4);

    // vector<int> Tree={3,10,1,6,14,4,7,13};
    // for (int i :Tree){
    //     insertNode(root,i);
    // }
// 7 1 15 2 -1 -1 -1 -1 
// /**************************************************
    TreeNode * root= new TreeNode(1);
    TreeNode * node1= new TreeNode(15);
    TreeNode * node2= new TreeNode(2);

    // TreeNode * node3= new TreeNode(4);
    // TreeNode * node4= new TreeNode(5);
    // TreeNode * node5= new TreeNode(6);
    // TreeNode * node6= new TreeNode(7);

    
    root->left=node1;
    root->right=node2;

    // node2->left=node5;
    // node2->right=node5;

    // node1->left=node3;
    // node1->right=node4;
// **************************************************/

    // preorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder(root);

    // cout<<searchNode(root,4)<<endl;
    // cout<<searchNode(root,8)<<endl;

    // insertNode(root,9);


    preorder(root);
    // root=deleteNode(root,4);
    cout<<endl;
    root=solve2(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    // inorder(root);
    return 0;
}