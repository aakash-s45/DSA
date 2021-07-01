#include <iostream>
using namespace std;
char arr[10];
void root(char arr[], char data)
{
    if (arr[0] != '\0')
    {
        cout << "Tree already has a root" << endl;
    }
    else
    {
        arr[0] = data;
    }
}
void left(char arr[], char data, int parent)
{
    if (arr[0] != '\0')
    {
        arr[2 * parent + 1] = data;
    }
    else
    {
        cout << "parent not present" << endl;
    }
}
void right(char arr[], char data, int parent)
{
    if (arr[0] != '\0')
    {
        arr[2 * parent +2] = data;
    }
    else
    {
        cout << "parent not present" << endl;
    }
}
void printTree(char arr[])
{
    for (int i = 0; i < 10; i++)
    {
        if(arr[i]!='\0'){
            cout<<arr[i];
        }
        else{
            cout<<"-";
        }
    }
}
int main()
{
    
    root(arr,'A');
    left(arr,'b',0);
    right(arr,'v',0);
    right(arr,'n',4);
    printTree(arr);


    // system("pause");
    return 0;
}
