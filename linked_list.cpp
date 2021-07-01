#include <iostream>
using namespace std;

typedef struct linked_list_node
{
    int num;
    int *pt;
    linked_list_node *next;
} list;

void show(list *ptr){
    while(ptr!=NULL){
        cout<<(ptr->num)<<endl;
        cout<<(ptr->pt)<<endl;
        cout<<"-------------"<<endl;
        ptr=ptr->next;
    }
}

int main()
{
    list *head;
    list *sec;
    list *thir;
    list *four;
    list *five;
    list *six;
    list *end;

    head=(list *)malloc(sizeof(list));
    sec=(list *)malloc(sizeof(list));
    thir=(list *)malloc(sizeof(list));
    four=(list *)malloc(sizeof(list));
    five=(list *)malloc(sizeof(list));
    six=(list *)malloc(sizeof(list));
    end=(list *)malloc(sizeof(list));

    // (*head).num = 8;
    head->num = 8;
    head->pt=&(head->num);
    head->next = sec;

    sec->num = 815;
    sec->pt=&(sec->num);
    sec->next=thir;

    thir->num = 35;
    thir->pt=&(thir->num);
    thir->next=four;

    four->num = 165;
    four->pt=&(four->num);
    four->next=five;

    five->num = 175;
    five->pt=&(five->num);
    five->next=six;

    six->num = 653;
    six->pt=&(six->num);
    six->next=end;

    end->num = 5;
    end->pt=&(end->num);
    end->next=NULL;

    show(head);
    cout<<(sizeof(list));
    //system("pause");
    return 0;
}
