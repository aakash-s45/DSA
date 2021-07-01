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

// 8,7,5,3,3

void SelectSort(int *a, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int key = a[i];
        int j = i + 1;

        int min = a[i];
        int index = i;
        for (j; j < len; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                index = j;
            }
        }
        a[i] = min;
        a[index] = key;
        cout << "PASS " << i + 1 << " gives -> ";
        disp(a, len);
    }
}

int main()
{
    int arr[] = {8, 7, 5, 3, 3, 56, 74, 12, 65, 85, 42};
    int *ptr = arr;
    int len;
    len = sizeof(arr) / sizeof(arr[0]);
    disp(arr, len);
    cout << "\n";

    SelectSort(arr, len);
    cout << "\n"
         << "Sorted array: ";
    disp(arr, len);

    system("pause");
    return 0;
}
