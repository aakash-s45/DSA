#include <iostream>
using namespace std;

typedef struct queue
{
    int f;
    int b;
    int size;
    int *arr;
} que;

void enqueue(que *q, int a);
int dequeue(que *q);
void disp(que *q);
int isEmpty(que *q);
int isFull(que *q);
int firstVal(que *q);
int lastVal(que *q);
int peek(que *q, int pos);

int main()
{
    que *q1;
    
    q1->size = 5;
    q1->b = q1->size -1;
    q1->f = q1->size -1;
    q1->arr = (int *)malloc(q1->size * sizeof(int));

    // printf("is empty: %d\n",isEmpty(q1));
    // printf("is Full: %d\n",isFull(q1));
    enqueue(q1, 56);
    enqueue(q1, 45);
    enqueue(q1, 23);
    enqueue(q1, 8);
    enqueue(q1, 17);
    printf("First element now is %d\n", firstVal(q1));
    printf("last element now is %d\n", lastVal(q1));
    
    int c = dequeue(q1);
    printf("dequeing %d .....\n", c);

    printf("First element now is %d\n", firstVal(q1));
    printf("last element now is %d\n", lastVal(q1));
    printf("element at position %d is %d",3,peek(q1,3));
    //printf("Element at postion %d is %d.\n", 2, peek(q1, 2));
    system("pause");
    return 0;
}

void enqueue(que *q, int a)
{
    if ((q->b + 1)% q->size == q->f)
    {
        cout<<"Queue is Full!"<<endl;
    }
    else
    {
        q->b=((q->b) + 1)%(q->size);
        q->arr[q->b]=a;
    }
}
int dequeue(que *q)
{
    if (!isEmpty(q))
    {
        q->f=(q->f +1 )%q->size;
        return q->arr[q->f];
    }
    else
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
}
int isEmpty(que *q)
{
    if (q->f == q->b)
    {
        return 1;
    }
    return 0;
}
int isFull(que *q)
{
    if ((q->b +1)%q->size==q->f)
    {
        return 1;
    }
    return 0;
}
int firstVal(que *q)
{
    if (!isEmpty(q))
    {
        int ind=(q->f);
        ind=(ind+1)%q->size;
        return q->arr[ind];
    }
    return -1;
}
int lastVal(que *q)
{
    if (!isEmpty(q))
    {
        return q->arr[q->b];
    }
    return -1;
}
int peek(que *q, int pos)
{
    if (!isEmpty(q))
    {
        que *q1 = q;
        int ind = (q1->f + pos)%q1->size;
        return q1->arr[ind];
    }
    return -1;
}