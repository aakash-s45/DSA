#include <iostream>
using namespace std;

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stk;

int push(stk stack, int data, int *ptr)
{
    ptr[stack.top + 1] = data;
    stack.top = stack.top + 1;
    return stack.top;
}
int pop(stk stack)
{
    stack.top = stack.top - 1;
    return stack.top;
}
void show(stk stack)
{
    for (int i = 0; i < stack.top + 1; i++)
    {
        cout << (stack.arr[i]) << endl;
    }
}

int main()
{
    stk s;
    int data = 16;
    s.size = 50;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));
    s.top = push(s, data, s.arr);
    show(s);
    cout << "top:" << s.top << endl;
    s.top = push(s, 15, s.arr);
    show(s);
    cout << "top:" << s.top << endl;
    s.top = push(s, 23, s.arr);
    show(s);
    cout << "top:" << s.top << endl;
    s.top = push(s, 26, s.arr);
    show(s);
    cout << "top:" << s.top << endl;
    s.top = push(s, 27, s.arr);
    show(s);
    cout << "top:" << s.top << endl;

    s.top = pop(s);
    show(s);
    cout << "top:" << s.top << endl;

    //system("pause");
    return 0;
}
