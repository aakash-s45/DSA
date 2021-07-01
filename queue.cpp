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
    q1->b = -1;
    q1->f = -1;
    q1->size = 50;
    q1->arr = (int *)malloc(q1->size * sizeof(int));

    printf("is empty: %d\n",isEmpty(q1));
    printf("is Full: %d\n",isFull(q1));
    enqueue(q1, 56);
    enqueue(q1, 45);
    enqueue(q1, 23);
    enqueue(q1, 17);
    disp(q1);
    printf("Element at postion %d is %d.\n", 2, peek(q1, 2));

    // printf("is empty: %d\n",isEmpty(q1));
    // printf("is Full: %d\n",isFull(q1));

    printf("First element now is %d\n", firstVal(q1));
    int c = dequeue(q1);
    printf("dequeing %d .....\n", c);
    printf("Element at postion %d is %d. Sir\n", 2, peek(q1, 2));

    //dequeue(q1);
    // cout<<val<<endl;
    //dequeue(q1);
    //cout<<c<<endl;

    disp(q1);
    system("pause");
    return 0;
}

void enqueue(que *q, int a)
{
    if (!isFull(q))
    {
        q->b++;
        q->arr[q->b] = a;
    }
    else
    {
        cout << "Queue is Full!" << endl;
    }
}
int dequeue(que *q)
{
    if (!isEmpty(q))
    {
        ++(q->f);
        return q->arr[q->f];
    }
    else
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
}
void disp(que *q)
{
    if (!isEmpty(q))
    {
        que *qu1;
        qu1 = q;
        int a = (qu1->f) + 1;
        int b = qu1->b;
        cout << "elements are:" << endl;
        for (a; a < b + 1; a++)
        {
            cout << qu1->arr[a] << "|";
        }
        cout << endl;
    }
    else{
        cout<<"Queue is empty"<<endl;
    }
}

int isEmpty(que *q)
{
    if (q->f == -1 && q->b == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(que *q)
{
    if (q->b == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int firstVal(que *q)
{
    if (!isEmpty(q))
    {
        return q->arr[q->f + 1];
    }
    return -1;
}
int lastVal(que *q)
{
    if (q->b != -1)
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
        int a = q1->f;
        return q1->arr[a + pos];
    }
    return -1;
}