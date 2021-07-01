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
void postOrder(node *root)
{
    if (root != NULL)
    {

        postOrder(root->left);
        postOrder(root->right);
        cout << "Data : " << root->data << endl;
    }
}
void preorder(node *root)
{
    if (root != NULL)
    {
        cout << "Data : " << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
}
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << "Data : " << root->data << endl;
        inOrder(root->right);
    }
}
int main()
{
    node *root = createnode(34);
    node *n1 = createnode(23);
    node *n2 = createnode(12);
    node *n3 = createnode(67);
    node *n4 = createnode(4);
    node *n5 = createnode(1);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;
    cout<<"InOrder\n";
    cout<<"-------\n";
    inOrder(root);
    cout<<"\n";

    cout<<"PreOrder\n";
    cout<<"--------\n";
    preorder(root);
    cout<<"\n";

    cout<<"PostOrder\n";
    cout<<"---------\n";
    postOrder(root);
    cout<<"\n";

    //system("pause");
    return 0;
}
