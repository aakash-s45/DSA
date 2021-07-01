#include <iostream>
using namespace std;

void disp(int *ptr, int len);
void merge(int *a, int low, int mid, int high);
void mergesort(int *a, int low, int high);

int main()
{
    int arr[] = {8, 9, 15, 46, 95, 104, 1, 7, 35, 42, 75, 93};
    // int arr1[] = {1,7,35,42,75,93};

    int m;
    m = sizeof(arr) / sizeof(arr[0]);
    // n = sizeof(arr1) / sizeof(arr1[0]);

    disp(arr, m);
    // disp(arr1, n);
    //merge(arr, 0, 5, m-1);
    mergesort(arr,0,11);
    disp(arr, m);

    system("pause");
    return 0;
}

void disp(int *ptr, int len)
{
    int *p = ptr;
    for (int i = 0; i < len; i++)
    {
        //printf("%d",p[i]);
        cout << p[i] << ",";
    }
    // printf("\n");
    cout<<endl;
}
void merge(int *a, int low, int mid, int high)
{
    int *c = (int *)malloc(100 * sizeof(int));
    int i, j, k;
    i = low;
    j = mid+1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] > a[j])
        {
            c[k] = a[j];
            k++;
            j++;
        }
        else
        {
            c[k] = a[i];
            k++;
            i++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }

    // Send element of c to a again
    for (int i = low; i <= high; i++)
    {
        a[i] = c[i];
    }
    free(c);
}

void mergesort(int *a, int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}