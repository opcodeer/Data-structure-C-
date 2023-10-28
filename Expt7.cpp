#include <iostream>
using namespace std;
void switchcasebinarysearch(int *arr,int element,int len){
    int low = 0,high = len-1,position = -1;
    while(low<high){
        int mid = (low+high)/2;
        if(arr[mid]==element){
            position = mid;
            break;
        }else{
            if(element>=arr[low]&&element<arr[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
    }
    switch (position)
    {
    case -1:
        cout<<"Element is not found"<<endl;
        break;
    default:
        cout<<"Element is found at index "<<position<<endl;
        break;
    }
}
int main()
{
    int arr[] = {2,-1,3,5,2,8,9};
    switchcasebinarysearch(arr,5,sizeof(arr)/sizeof(arr[0]));
    return 0;
}