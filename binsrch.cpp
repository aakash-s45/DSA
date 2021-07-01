#include <iostream>
using namespace std;



int main()
{
    int arr[15]={1,12,53,68,95,74,86,96,151,189,214,215,268,279,315};
    int num;
    int low;
    int high;
    int mid;

    cout<<"Enter the number to search"<<endl;
    cin>>num;
    low=0;
    high=14;
    mid=(high + low)/2;
    if(arr[low]==num){
        cout<<arr[low]<<" is at index "<<low<<endl;
    }
    else if (arr[high]==num)
    {
        cout<<arr[high]<<" is at index "<<high<<endl;
    }
    else if (arr[mid]==num)
    {
        cout<<arr[mid]<<" is at index "<<mid<<endl;
    }


    else{
        while((arr[mid]-num)!=0){
            if(num > arr[low] && num < arr[mid] ){
                high=mid;
                low=low;
                mid=(high+low)/2;
                cout<<"high:"<<high<<endl;
                cout<<"low:"<<low<<endl;
                cout<<"mid:"<<mid<<endl;
                //continue;
            }
            else if(num >arr[mid] && num <arr[high] ){
                low=mid;
                high=high;
                mid=(high+low)/2;
                cout<<"high:"<<high<<endl;
                cout<<"low:"<<low<<endl;
                cout<<"mid:"<<mid<<endl;
                //continue;
            }
            if((high-low)<=1){
                cout<<"not found";
                return 0;
            }
            //mid=(high+low)/2;
            
    }
    cout<<arr[mid]<<" is at index "<<mid<<endl;
    }
    
    //system("pause");
    return 0;
}
