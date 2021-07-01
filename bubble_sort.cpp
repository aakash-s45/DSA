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

void bubbleSort(int *ptr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << "pass number:" << i + 1 << endl;
        for (int j = 0; j < n - 1; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                int temp;
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}

void AdapBubbleSort(int *ptr, int n)
{
    int val = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int val = 1;
        // cout << "pass number:" << i + 1 << endl;
        for (int j = 0; j < n - 1; j++)
        {

            if (ptr[j] > ptr[j + 1])
            {
                val = 0;
                int temp;
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
        cout << "PASS " << i + 1 << " gives -> ";
        disp(ptr, n);
        if (val)
        {
            return;
        }
    }
}

int main()
{
    //int arr[] = {8,7,5,3,3};
    // int arr[] = {24, 5, 45, 96, 7, 52, 96, 74};
    int arr[] = {1, 72, 33, 36, 13, 4, 51, 65, 75, 64, 7, 17, 24, 45, 52, 74, 96, 91};
    int len;

    len = sizeof(arr) / sizeof(arr[0]);
    disp(arr, len);
    cout << endl;

    // bubbleSort(ptr, len);
    // cout << "after Sorting ...." << endl;
    // disp(ptr, len);
    AdapBubbleSort(arr, len);
    // disp(ptr1, len);

    system("pause");
    return 0;
}
