#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createnode(int data)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
// void postOrder(node *root)
// {
//     if (root != NULL)
//     {

//         postOrder(root->left);
//         postOrder(root->right);
//         cout << "Data : " << root->data << endl;
//     }
// }
// void preorder(node *root)
// {
//     if (root != NULL)
//     {
//         cout << "Data : " << root->data << endl;
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

int checkInc(int *ptr, int n)
{
    int val = 0;
    for (int i = 0; i < n-1; i++)
    {
        val=1;
        if(ptr[i]>ptr[i+1]){
            val=0;
        }
    }
    return val;
}

int ar[100];
int ind=0;

void inOrder(node *root)
{
    
    if (root != NULL)
    {
        inOrder(root->left);
        ar[ind]=root->data;
        ind++;
        cout << "Data : " << root->data << endl;
        inOrder(root->right);
    }
}
// int BST(node *root)
// {
//     static node * prev=NULL;
//     if (root != NULL)
//     {
//         if(!BST(root->left)){
//             return 0;
//         }
//         if(prev!=NULL && root->data <= prev->data){
//             return 0;
//         }
//         prev = root;
//         return BST(root->right);
        
//     }
//     else{
//         return 1;
//     }
// }
int main()
{
    node *root = createnode(12);
    node *n1 = createnode(7);
    node *n2 = createnode(15);
    node *n3 = createnode(3);
    node *n4 = createnode(8);
    node *n5 = createnode(16);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;
    cout<<"InOrder\n";
    cout<<"-------\n";
    inOrder(root);
    cout<<"\n";

    // for (int i = 0; i < 6; i++)
    // {
    //     cout<<ar[i]<<endl;
    // }
    cout<<checkInc(ar,ind);
    

    // cout<<BST(root);


    //system("pause");
    return 0;
}
