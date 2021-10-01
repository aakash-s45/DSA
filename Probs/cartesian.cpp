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

/*
Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1
*/

// {2,1,3}
// start=0 end=2 maxi=
// start=0 end=2
TreeNode* makeTree(vector<int> &vec,int start,int end){
    if(start>end)return nullptr;
    int maxidx=0;
    int maxval=INT_MIN;
    for(int i=start;i<=end;i++){
        if(vec[i]>maxval){
            maxval=vec[i];
            maxidx=i;
        }
    }
    TreeNode* root=new TreeNode(vec[maxidx]);
    root->left=makeTree(vec,start,maxidx-1);
    root->right=makeTree(vec,maxidx+1,end);
    return root;
}
int main(){
    // TreeNode * root= new TreeNode(4);

    // vector<int> Tree={3,10,1,6,14,4,7,13};
    // for (int i :Tree){
    //     insertNode(root,i);
    // }
// 7 1 15 2 -1 -1 -1 -1 
// /**************************************************
    // TreeNode * root= new TreeNode(1);
    // TreeNode * node1= new TreeNode(15);
    // TreeNode * node2= new TreeNode(2);

    // TreeNode * node3= new TreeNode(4);
    // TreeNode * node4= new TreeNode(5);
    // TreeNode * node5= new TreeNode(6);
    // TreeNode * node6= new TreeNode(7);

    
    // root->left=node1;
    // root->right=node2;

    // node2->left=node5;
    // node2->right=node5;

    // node1->left=node3;
    // node1->right=node4;
// **************************************************/
    vector<int> vec={2,1,3};
    TreeNode * root=makeTree(vec,0,vec.size()-1);

    preorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}