#include <iostream>
#include<algorithm>
using namespace std;
void Bubblesort(int *arr,int len){
    bool swapped;
    for(int i=0;i<len-1;i++){
        swapped = false;
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped==false) break;
    }
}
int main()
{
    int arr[] = {45,23,64,42,58,11};
    int len = sizeof(arr)/sizeof(arr[0]);
    Bubblesort(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}