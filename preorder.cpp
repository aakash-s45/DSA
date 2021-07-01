#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createnode(int data){
    node *n;
    n=(node *)malloc(sizeof(node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void preorder(node *root){
    if(root!=NULL){
        cout<<"Data : "<<root->data<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    node *root=createnode(34);
    node *n1=createnode(23);
    node *n2=createnode(12);

    root->left=n1;
    root->right=n2;

    preorder(root);

    //system("pause");
    return 0;
}
