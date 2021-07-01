#include <iostream>
using namespace std;

void disp(int *ptr, int len)
{
    int *p = ptr;
    for (int i = 0; i < len; i++)
    {
        cout << p[i] << ",";
    }
    cout << endl;
}

void insertsort(int *ptr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = ptr[i];
        int j = i - 1;
        while (ptr[j] > key && j >= 0)
        {
            ptr[j + 1] = ptr[j];
            j--;
        }
        ptr[j + 1] = key;
        cout<<"PASS "<<i+1<<" gives -> ";
        disp(ptr,n);
    }
}



int main()
{
    int arr[] = {11, 7, 5, 3, 3, 24, 5, 45, 96, 7, 52, 96, 74};
    int *ptr = arr;
    int len;
    len = sizeof(arr) / sizeof(arr[0]);
    disp(arr, len);
    cout<<"\n";
    insertsort(arr, len);
    // disp(arr, len);
    // insertsort(ptr, len);

    system("pause");
    return 0;
}
