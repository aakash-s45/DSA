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
struct T_node
{
    TreeNode * node=nullptr;
    int HDist=0;
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

vector<vector<int>> verticalTraversal(TreeNode* root){
    // level order traversal then store element according to horizontal distance
    map<int,vector<int>> mp;
    vector<vector<int>> res;
    if(root==nullptr)return res;
    
    queue<T_node> qu;
// push the root node in queue
    T_node rootNode;
    rootNode.HDist=0;
    rootNode.node=root;

    qu.push(rootNode);
    T_node nullstr;
    qu.push(nullstr);
// while queue is not empty
    while(!qu.empty()){
        // pop the element and check it is null or not
        T_node tempStruct=qu.front();
        TreeNode* temp = tempStruct.node;
        qu.pop();

        if(temp){
            if(mp.find(tempStruct.HDist)==mp.end()){
                vector<int> nodeVec;
                nodeVec.push_back(temp->val);
                mp.insert(make_pair(tempStruct.HDist,nodeVec));
            }
            else{
                mp[tempStruct.HDist].push_back(temp->val);
            }
            if(temp->left){
                T_node leftstr;
                leftstr.HDist=tempStruct.HDist-1;
                leftstr.node=temp->left;
                qu.push(leftstr);
            }
            if(temp->right){
                T_node rightstr;
                rightstr.HDist=tempStruct.HDist+1;
                rightstr.node=temp->right;
                qu.push(rightstr);
            }
        }
        else{
            if(!qu.empty())qu.push(nullstr);
        }
    }
    for(auto a:mp){
        res.push_back(a.second);
    }
    return res;
}

// vector<vector<int>> levelOrder(TreeNode* root){
//     vector<vector<int>> res;
//     if(root==nullptr)return res;

//     vector<int> node;
//     queue<TreeNode*> qu;
//     qu.push(root);
//     qu.push(nullptr);
//     while(!qu.empty()){
//         TreeNode* temp = qu.front();
//         qu.pop();
//         if(temp){
//             // if temp is not null push its left and right child to this. 
//             node.push_back(temp->val);
//             if(temp->left)qu.push(temp->left);
//             if(temp->right)qu.push(temp->right);
//         }
//         else{
//             // IF TEMP IS NULL that means new level started, again push the null
//             res.push_back(node);
//             node.clear();
//             if(!qu.empty())qu.push(nullptr);
//         }
//     }
//     return res;
// }

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

int main(){
    // TreeNode * root= new TreeNode(4);

    // vector<int> Tree={3,10,1,6,14,4,7,13};
    // for (int i :Tree){
    //     insertNode(root,i);
    // }

/**************************************************/
    TreeNode * root= new TreeNode(4);
    TreeNode * node1= new TreeNode(6);
    TreeNode * node2= new TreeNode(2);
    TreeNode * node3= new TreeNode(3);
    TreeNode * node4= new TreeNode(5);
    TreeNode * node5= new TreeNode(1);
    TreeNode * node6= new TreeNode(7);
/*
        4
    2      6
 1    3  5   7
*/
    
    root->left=node2;
    root->right=node1;

    node2->left=node5;
    node2->right=node3;

    node1->left=node4;
    node1->right=node6;
/**************************************************/

    // preorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder(root);

    // cout<<searchNode(root,4)<<endl;
    // cout<<searchNode(root,8)<<endl;

    // insertNode(root,9);


    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    vector<vector<int>> res=verticalTraversal(root);
    disp(res);
    return 0;
}