#include <iostream>
using namespace std;

typedef struct doubleNode
{
    int num;
    struct doubleNode *prev;
    struct doubleNode *next;
} dNode;

void showF(dNode *head){
    dNode *ptr=head;
    cout<<"|";
    while(ptr!=NULL){
        cout<<ptr->num<<"|";
        ptr=ptr->next;
    }

}
void showB(dNode *end){
    dNode *ptr=end;
    cout<<"|";
    while(ptr!=NULL){
        cout<<ptr->num<<"|";
        ptr=ptr->prev;
    }

}

int main()
{
    dNode *head;
    dNode *sec;
    dNode *thi;
    dNode *four;
    dNode *fif;
    dNode *end;

    head = (dNode *)malloc(sizeof(dNode));
    sec = (dNode *)malloc(sizeof(dNode));
    thi = (dNode *)malloc(sizeof(dNode));
    four = (dNode *)malloc(sizeof(dNode));
    fif = (dNode *)malloc(sizeof(dNode));
    end = (dNode *)malloc(sizeof(dNode));

    head->num=45;
    head->prev=NULL;
    head->next=sec;

    sec->num=48;
    sec->prev=head;
    sec->next=thi;

    thi->num=50;
    thi->prev=sec;
    thi->next=four;

    four->num=52;
    four->prev=thi;
    four->next=fif;

    fif->num=54;
    fif->prev=four;
    fif->next=end;

    end->num=56;
    end->prev=fif;
    end->next=NULL;

    // showF(head);
    // cout<<endl;
    // showB(end)
    showF(four);
    cout<<endl;
    showB(four);
    return 0;
}
