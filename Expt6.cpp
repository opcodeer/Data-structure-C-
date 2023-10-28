#include <iostream>
using namespace std;
void switchcaselinearsearch(int arr[],int element,int len){
    int position = -1;
    for(int i=0;i<len;i++){
        if(arr[i] == element){
            position = i;
            break;
        }
    }
    switch (position)
    {
    case -1:
       cout<<"Element is not found"<<endl;
       break;
    default:
       cout<<"Element is found at position(index) "<<position<<endl;
       break;
    }
}
int main()
{
    int arr[] = {2,-1,3,5,2,8,9};
    switchcaselinearsearch(arr,5,sizeof(arr)/sizeof(arr[0]));
    return 0;
}