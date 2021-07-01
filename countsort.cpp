#include <iostream>
using namespace std;

void disp(int *ptr, int len);
int max(int *arr, int len);
void countsort(int *a, int len);

int main()
{
    int arr[] = {8, 7, 5, 3, 3, 56, 74, 12, 65, 85, 42};
    int len;
    len = sizeof(arr) / sizeof(arr[0]);
    disp(arr, len);
    countsort(arr, len);
    disp(arr, len);
    system("pause");
    return 0;
}

void disp(int *ptr, int len)
{
    int *p = ptr;
    for (int i = 0; i < len; i++)
    {
        cout << p[i] << ",";
    }
    cout << endl;
}
int max(int *arr, int len)
{
    int max;
    max = arr[0];
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void countsort(int *a, int len)
{
    int mx = max(a, len);
    int ind = 0;
    int *count = (int *)malloc((mx + 1) * sizeof(int));

    for (int i = 0; i <= mx; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        count[a[i]]++;
    }

    for (int i = 0; i <= mx; i++)
    {
        while (count[i] != 0)
        {
            count[i]--;
            a[ind] = i;
            ind++;
        }
    }
    free(count);
}
