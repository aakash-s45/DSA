#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct stack
{
    int top;
    int size;
    node *ptr;

}stk;

int peek(stk *stack, int pos){
    node* p=stack->ptr;
    for (int i = 0;( i < pos-1 && p!=NULL); i++)
    {
        p=p->next;
    }
    return p->data;
}

void push(stk *stack,int num){
    node *nod;
    nod=(node *)malloc(sizeof(node));
    nod->data=num;
    nod->next=stack->ptr;
    stack->ptr=nod;
    stack->top++;
}
int pop(stk *stack){
    int val;
    node *fr;
    fr=stack->ptr;
    val=stack->ptr->data;
    stack->ptr=stack->ptr->next;
    stack->top--;
    free(fr);
    return val;
}
int isempty(stk *stack){
    if(stack->ptr==NULL){
        return 1;
    }
    return 0;
}
int isfull(stk *stack){
    if(stack->top>=(stack->size)-1){
        return 1;
    }
    return 0;
}

int main()
{

    stk *stack=(stk *)malloc(sizeof(stk));
    stack->top=-1;
    stack->size=50;
    stack->ptr=NULL;

    cout<<"before adding...."<<endl;
    cout<<"isempty:"<<isempty(stack)<<endl;

    push(stack,45);

    // cout<<"after adding...."<<endl;
    // cout<<"isempty:"<<isempty(stack)<<endl;

    push(stack,56);
    push(stack,59);
    push(stack,78);
    push(stack,98);
    for (int i = 1; i < stack->top+2; i++)
    {
        cout<<"element at position "<<i<<" : ";
        cout<<peek(stack,i)<<endl;
    }

    // cout<<"pop:"<<pop(stack)<<endl;
    // for (int i = 1; i < stack->top+2; i++)
    // {
    //     cout<<"element at position "<<i<<" : ";
    //     cout<<peek(stack,i)<<endl;
    // }
    cout<<"pop:"<<pop(stack)<<endl;
    // for (int i = 1; i < stack->top+2; i++)
    // {
    //     cout<<"element at position "<<i<<" : ";
    //     cout<<peek(stack,i)<<endl;
    // }

    //system("pause");
    return 0;
}
