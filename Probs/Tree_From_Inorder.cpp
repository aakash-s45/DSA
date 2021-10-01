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
// 1 2 3 4 5 6 7 8
// 0 1 2 3 4 5 6 7



TreeNode* create(vector<int> vec,int start,int end){
    if(start>end)return nullptr;
    int mid=start+(end-start)/2;
    TreeNode *node=new TreeNode(vec[mid]);
    node->left=create(vec,start,mid-1);
    node->right=create(vec,mid+1,end);
    return node;
}

int main(){
    TreeNode * root= new TreeNode(4);
    vector<int> vec={1,3,5,6,8,9,11};
    TreeNode* newtree=nullptr;
    newtree = create(vec,0,vec.size()-1);
/**************************************************
    // TreeNode * root= new TreeNode(4);
    // TreeNode * node1= new TreeNode(6);
    // TreeNode * node2= new TreeNode(2);
    // TreeNode * node3= new TreeNode(3);
    // TreeNode * node4= new TreeNode(5);
    // TreeNode * node5= new TreeNode(1);
    // TreeNode * node6= new TreeNode(7);

    
    // root->left=node2;
    // root->right=node1;

    // node2->left=node5;
    // node2->right=node3;

    // node1->left=node4;
    // node1->right=node6;
**************************************************/
    preorder(newtree);
    cout<<endl;
    inorder(newtree);
    return 0;
}