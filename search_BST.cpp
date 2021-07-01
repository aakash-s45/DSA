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

void inOrder(node *root)
{

    if (root != NULL)
    {
        inOrder(root->left);
        cout << "Data : " << root->data << endl;
        inOrder(root->right);
    }
}

void search(node *root, int n)
{
    node *ptr = root;
    int index = 0;
    while (ptr != NULL)
    {
        if (ptr->data != n)
        {
            if (n > ptr->data)
            {
                ptr = ptr->right;
                index++;
            }
            if (n < ptr->data)
            {
                ptr = ptr->left;
                index++;
            }
        }

        else
        {
            cout << "YES! It is present in BST";
            return;
        }
        
        cout<<index<<endl;
    }
    if (ptr == NULL)
    {
        cout << "Sorry! it is not present in BST given";
    }
}

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
    // cout << "InOrder\n";
    // cout << "-------\n";
    // inOrder(root);
    // cout << "\n";
    search(root, 17);
    return 0;
}
