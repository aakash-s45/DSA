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

list *atHead(list *head,list *newNode){
    list *ptr=head;
    newNode->next=head;
    head=newNode;
    return head;
}
void atEnd(list *head,int dat){
    list *ptr=head;
    list *node;
    node=(list *)malloc(sizeof(list));
    node->num=dat;
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=node;
    node->next=NULL;
    
}
void changeIN(list *head, int ind, int dat)
{
    list *newl;
    list *ptr = head;
    newl = (list *)malloc(sizeof(list));
    newl->num = dat;

    for (int i = 0; i < (ind - 1); i++)
        {
            ptr = ptr->next;
        }
        newl->next = ptr->next;
        ptr->next = newl;
    
};
void afterNode(list *head, list *prev)
{
    list *newl;
    list *ptr = head;
    newl = (list *)malloc(sizeof(list));
    newl->num = 420;
    newl->next=prev->next;
    prev->next=newl;
    
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
    head->pt = &(head->num);
    head->next = sec;

    sec->num = 815;
    sec->pt = &(sec->num);
    sec->next = thir;

    thir->num = 35;
    thir->pt = &(thir->num);
    thir->next = four;

    four->num = 165;
    four->pt = &(four->num);
    four->next = five;

    five->num = 175;
    five->pt = &(five->num);
    five->next = six;

    six->num = 653;
    six->pt = &(six->num);
    six->next = end;

    end->num = 5;
    end->pt = &(end->num);
    end->next = NULL;
    show(head);
    
    newNode->num = 23;

    cout<<endl;
    int ind, dat;
    cout << "enter the index :" << endl;
    cin >> ind;
    if (ind == 0)
    {
        head = atHead(head,newNode);
    }
    else if(ind == -1)
    {   cout << "enter the number :" << endl;
        cin >> dat;
        atEnd(head,dat);
        // show(head);
    }
    else if(ind == -2)
    {  
        afterNode(head,four);
        // show(head);
    }
    else{
        cout << "enter the number :" << endl;
        cin >> dat;
        changeIN(head,ind,dat);
        
    }
    show(head);
}
