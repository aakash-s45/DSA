#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct que
{
    node *front;
    node *rear;
} que;

void enqueue(que *q, int val)
{
    node *nu = (node *)malloc(sizeof(node));

    if (nu == NULL)
    {
        printf("Queue is Full!\n");
    }
    else
    {
        nu->data = val;
        nu->next = NULL;
        if (q->front == NULL)
        {
            q->front = q->rear = nu;
        }
        else
        {
            q->rear->next = nu;
            q->rear = nu;
        }
    }
}
int dequeue(que *q)
{
    node *ptr = (node *)malloc(sizeof(node));
    int val=-1;
    if (q->front == NULL)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        ptr=q->front;
        val= q->front->data;
        q->front=q->front->next;
        free(ptr);
    }
    return val;
}

void show(que *q){
    node* ptr=q->front;

    while(ptr!=NULL){
        cout<<(ptr->data)<<endl;
        cout<<"-------------"<<endl;
        ptr=ptr->next;
    }
}

int isEmpty(que *q){
    if(q->front==NULL){
        return 1;
    }
    return 0;
}
int firstVal(que *q)
{
    return q->front->data;
}
int lastVal(que *q)
{
    return q->rear->data;
}
int main()
{
    que *qu;
    qu->front = NULL;
    qu->rear = NULL;
    enqueue(qu, 56);
    enqueue(qu, 45);
    enqueue(qu, 21);
    show(qu);
    printf("First Val: %d\n",firstVal(qu));
    printf("Last Val: %d\n",lastVal(qu));
    printf("Dequeued Value: %d\n",dequeue(qu));
    dequeue(qu);
    dequeue(qu);
    printf("Is Empty: %d\n",isEmpty(qu));
    enqueue(qu, 21);
    enqueue(qu, 28);
    show(qu);
    printf("Is Empty: %d\n",isEmpty(qu));
    // printf("Dequeued Value: %d\n",dequeue(qu));
    printf("First Val: %d\n",firstVal(qu));
    printf("Last Val: %d\n",lastVal(qu));
    
    



    //system("pause");
    return 0;
}
