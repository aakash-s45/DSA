#include <iostream>
using namespace std;

typedef struct linked_list_node
{
    int num;
    int *pt;
    linked_list_node *next;
} list;

void show(list *ptr)
{
    cout << "|";
    while (ptr != NULL)
    {
        cout << (ptr->num) << "|";
        // cout<<(ptr->pt)<<endl;
        // cout<<"-------------"<<endl;
        ptr = ptr->next;
    }
}

list *atHead(list *head)
{
    list *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
void atEnd(list *head)
{
    list *ptr1 = head;
    list *ptr2 = head;
    ptr2 = ptr2->next;

    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = NULL;
    free(ptr2);
}
void changeIN(list *head, int ind)
{
    list *ptr = head;
    list *p = head;
    p = p->next;

    for (int i = 0; i < (ind - 1); i++)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);
};
void afterNode(list *head, list *prev)
{
    list *ptr = prev;
    ptr = ptr->next;
    prev->next = ptr->next;
    free(ptr);
};

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
    end->next = NULL;

    show(head);

    cout << endl;
    int ind;
    cout << "enter the index :" << endl;
    cin >> ind;

    if (ind == 0)
    {
        head = atHead(head);
    }
    else if (ind == -1)
    {
        atEnd(head);
    }
    else if (ind == -2)
    {
        afterNode(head, four);
    }
    else
    {
        changeIN(head, ind);
    }
    show(head);
}
