#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 

/*
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2

     z                               z                           x
    / \                            /   \                        /  \ 
   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2


  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(z)       z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4

   z                            z                            x
  / \                          / \                          /  \ 
T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
   x   T4                      T2   y                  T1  T2  T3  T4
  / \                              /  \
T2   T3                           T3   T4
 
*/


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    int height;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr),height(1){}
};

int height(TreeNode* node){
    if(node)return node->height;
    return 0;
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
void postorder(TreeNode*root){
    if(root==nullptr)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<", ";
}


TreeNode* RightRotate(TreeNode* root){
    TreeNode* NewRoot=root->left;
    TreeNode* leftRight=NewRoot->right;//right of left child in original tree

    root->left=leftRight;
    NewRoot->right=root;

    root->height=max(height(root->left),height(root->right))+1;
    NewRoot->height=max(height(NewRoot->left),height(NewRoot->right))+1;
    return NewRoot;
}

TreeNode* LeftRotate(TreeNode* root){
    TreeNode* NewRoot=root->right;
    TreeNode* RightLeft=NewRoot->left;

    root->right=RightLeft;
    NewRoot->left=root;

    root->height=max(height(root->left),height(root->right))+1;
    NewRoot->height=max(height(NewRoot->left),height(NewRoot->right))+1;
    return NewRoot;
}

int BalanceFactor(TreeNode* node){
    if(node)return height(node->left)-height(node->right);
    return 0;
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

TreeNode* insertNode(TreeNode* root, int key){
    /* Find the place at which we insert the node and then insert it*/
    if(root==nullptr){
        TreeNode * newNode=new TreeNode(key);
        return newNode;
    }
    if(root->val==key)return root;
    if(key<root->val)root->left=insertNode(root->left,key);
    else if(key>root->val)root->right=insertNode(root->right,key);

    // if curr root is the node in which we have to 
    root->height=max(height(root->left),height(root->right))+1;
    int balFactor=BalanceFactor(root);

    // balfactor > 1 means left tree has more height, have to rotate right
    // balfactor < -1 means right tree has more height, have to rotate left
    // now check for these __right or __left
    // if node is inserted to left of left, LL
    // if node is inserted to right of left, LR
    // if node is inserted to left of right ,RL
    // if node is inserted to right of right ,RR
    if(balFactor > 1 and key < root->left->val){
        return RightRotate(root);//LL
    }
    if(balFactor > 1 and key > root->left->val){
        // first left rotate then right rotate
        root->left=LeftRotate(root->left);
        return RightRotate(root);//LR
    }

    if(balFactor < -1 and key > root->right->val){
        return LeftRotate(root);//RR
    }
    if(balFactor>1 and key < root->left->val){
        root->right=RightRotate(root->right);
        return LeftRotate(root);//RL
    }
    return root;

}
int main(){
    TreeNode* root=nullptr;
    root=insertNode(root,10);
    root=insertNode(root,14);
    root=insertNode(root,6);
    root=insertNode(root,9);
    root=insertNode(root,3);
    root=insertNode(root,12);

    inorder(root);

    return 0;
}