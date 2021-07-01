#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

void preorder(node *root){
    if(root!=NULL){
        cout<<"Data : "<<root->data<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    node *n0=(node *)malloc(sizeof(node));
    node *n1=(node *)malloc(sizeof(node));
    node *n2=(node *)malloc(sizeof(node));

    n0->data=21;
    n1->data=34;
    n2->data=43;

    n0->left=n1;
    n0->right=n2;
    n1->left=NULL;
    n1->right=NULL;
    n2->left=NULL;
    n2->right=NULL;

    preorder(n0);

    system("pause");
    return 0;
}
