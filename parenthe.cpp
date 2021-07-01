#include <iostream>
using namespace std;
#include <string.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
} stk;

int isEmpty(stk *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        cout<<"Stack Full"<<endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(stk *ptr)
{
    if (isEmpty(ptr))
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}


int main()
{
    string exp;

    stk *stac = (stk *)malloc(sizeof(stk));
    stac->size = 5000;
    stac->top = -1;
    stac->arr = (char *)malloc(stac->size * sizeof(char));
    

    cout << "Stack created..." << endl;
    cout << "enter the expression" << endl;
    getline(cin, exp);
    char *ptr;
    ptr = &exp[0];
    while(*ptr!='\0'){
        // cout<<*ptr;
        if(*ptr=='('){
            cout<<*ptr;
            push(stac,'(');
        }
        else if(*ptr==')'){
            cout<<*ptr;
            if(isEmpty(stac)){
                cout<<endl;
                cout<<"not balanced"<<endl;
                return 0;
            }
            else{
                pop(stac);
            }
            
        }
        else{
            cout<<" ";
        }
        ptr++;
    }
    cout<<endl;
    if(isEmpty(stac)){
        cout<<"balanced"<<endl;
    }
    else{
        cout<<"not balanced"<<endl;
    }

    // system("pause");
    return 0;
}

