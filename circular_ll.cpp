#include <iostream>
using namespace std;

typedef struct linked_list_node
{
    int num;
    int *pt;
    linked_list_node *next;
} list;

void show(list *head)
{
    list *ptr = head;
    cout << "|";
    do
    {
        cout << ptr->num << "|";
        ptr = ptr->next;
    } while (ptr != head);
}

list *atHead(list *head, int data)
{
    list *node = (list *)malloc(sizeof(list));
    node->num = data;
    list *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = node;
    node->next = head;
    head = node;
    return head;
}
// void atEnd(list *head,int dat){
//     list *ptr=head;
//     list *node;
//     node=(list *)malloc(sizeof(list));
//     node->num=dat;
//     while(head->next!=NULL){
//         head=head->next;
//     }
//     head->next=node;
//     node->next=NULL;

// }
// void changeIN(list *head, int ind, int dat)
// {
//     list *newl;
//     list *ptr = head;
//     newl = (list *)malloc(sizeof(list));
//     newl->num = dat;

//     for (int i = 0; i < (ind - 1); i++)
//         {
//             ptr = ptr->next;
//         }
//         newl->next = ptr->next;
//         ptr->next = newl;

// };
// void afterNode(list *head, list *prev)
// {
//     list *newl;
//     list *ptr = head;
//     newl = (list *)malloc(sizeof(list));
//     newl->num = 420;
//     newl->next=prev->next;
//     prev->next=newl;

// };

int main()
{
    list *head;
    list *sec;
    list *thir;
    list *four;
    list *five;
    list *six;
    list *end;
    list *newl;
    list *newNode;

    head = (list *)malloc(sizeof(list));
    sec = (list *)malloc(sizeof(list));
    thir = (list *)malloc(sizeof(list));
    four = (list *)malloc(sizeof(list));
    five = (list *)malloc(sizeof(list));
    six = (list *)malloc(sizeof(list));
    end = (list *)malloc(sizeof(list));

    newNode = (list *)malloc(sizeof(list));

    // (*head).num = 8;
    head->num = 8;
    head->next = sec;

    sec->num = 815;
    sec->next = thir;

    thir->num = 35;
    thir->next = four;

    four->num = 165;
    four->next = five;

    five->num = 175;
    five->next = six;

    six->num = 653;
    six->next = end;

    end->num = 5;
    end->next = head;
    show(head);
    cout << endl;
    head = atHead(head, 297);
    show(head);
}
