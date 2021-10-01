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

TreeNode* inorderPre(TreeNode* root){
    TreeNode* leftSubtree=root->left;
    while(leftSubtree->right!=nullptr){
        leftSubtree=leftSubtree->right;
    }
    return leftSubtree;
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
bool path(TreeNode* root,int val,vector<int> &vec){
    if(root==nullptr)return false;
    vec.push_back(root->val);
    if(root->val==val)return true;
    if(path(root->left,val,vec)||path(root->right,val,vec))return true;
    vec.pop_back();
    return false;
}

// A:bigger string
// B:smaller string
// mode:1 reverse enable
// mode:0 disable
string add(string a,string b,int mode=1){
    string c;
    if(a.length()<b.length())return c=add(b,a,mode);
    if(mode){
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
    }

    int carry=0;
    int val;
    for (int i = 0; i < b.length(); i++){
        val=((b[i]-'0')+(a[i]-'0')+carry)%10;
        carry=((b[i]-'0')+(a[i]-'0')+carry)/10;
        c.push_back(val+'0');
    }
    if(b.length()<a.length()){
        for (int i = b.length(); i < a.length(); i++){
            val=(carry+(a[i]-'0'))%10;
            carry=(carry+(a[i]-'0'))/10;
            c.push_back(val+'0');
        }
        if(carry!=0)c.push_back(carry+'0');
        
    }
    else if(carry!=0)c.push_back(carry+'0');
    if(mode)reverse(c.begin(),c.end());
    return c;
}

// void Root_to_leaf(TreeNode* root,string &s,vector<string>&res,string &ans){
//     if(root==NULL)return;
//     s.push_back(root->val+'0');
//     Root_to_leaf(root->left,s,res,ans);
//     Root_to_leaf(root->right,s,res,ans);
//     if(root->left==nullptr and root->right==nullptr){
//         ans=add(ans,s);
//         res.push_back(s);
//     }
//     s.pop_back();
//     return;
// }

// void Root_to_leaf(TreeNode* root,vector<int> &node,vector<vector<int>>&res){
//     if(root==NULL)return;
//     node.push_back(root->val);
//     Root_to_leaf(root->left,node,res);
//     Root_to_leaf(root->right,node,res);
//     if(root->left==nullptr and root->right==nullptr)res.push_back(node);
//     node.pop_back();
//     return;
// }

void Root_to_leaf(TreeNode* root,int &resVal,int &curVal,int &mult){
    if(root==NULL)return;

    curVal=(curVal*10)+(root->val);

    Root_to_leaf(root->left,resVal,curVal,mult);
    Root_to_leaf(root->right,resVal,curVal,mult);

    if(root->left==nullptr and root->right==nullptr){
        resVal+=(curVal%1003);
    }
    curVal/=10;
    return;
}
int main(){

    TreeNode * root= new TreeNode(4);
    TreeNode * node1= new TreeNode(6);
    TreeNode * node2= new TreeNode(2);
    TreeNode * node3= new TreeNode(3);
    TreeNode * node4= new TreeNode(5);
    TreeNode * node5= new TreeNode(1);
    TreeNode * node6= new TreeNode(7);

    
    root->left=node2;
    root->right=node1;

    node2->left=node5;
    node2->right=node3;

    node1->left=node4;
    node1->right=node6;

    int resVal=0;
    int curVal=0;
    int mult=1;
    Root_to_leaf(root,resVal,curVal,mult);

    inorder(root);
    cout<<endl;


    cout<<endl;
    cout<<resVal%1003;
    
    return 0;
}