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

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (j > i);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quicksort(int *arr, int low, int high)
{
    int partitionInd;

    if (low < high)
    {
        partitionInd = partition(arr, low, high);
        quicksort(arr, low, partitionInd - 1);
        quicksort(arr, partitionInd + 1, high);
    }
}

int main()
{
    int arr[] = {8, 7, 5, 3, 3, 56, 74, 12, 65, 85, 42};
    int len;
    len = sizeof(arr) / sizeof(arr[0]);
    disp(arr, len);
    quicksort(arr,0,10);
    disp(arr, len);

    //system("pause");
    return 0;
}
