#include <iostream>
using namespace std;
int index = -1;
int len = 0;// length of the array
int maxlen = 100;
void insertionatend(int *arr,int ele){
    if(len>=maxlen){
        cout<<"Array is full, Insertion cannot be done"<<endl;
    }
    index++;
    arr[index] = ele;
    len++;
}
void deletionatend(int *arr){
    if(len==0||index==-1){
        cout<<"No element to delete"<<endl;
        return;
    }
    index--;
    len--;
}
int main()
{
    int *arr;
    insertionatend(arr,1);
    insertionatend(arr,2);
    insertionatend(arr,3);
    insertionatend(arr,4);
    insertionatend(arr,5);
    cout<<"The array after insertion is "<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    deletionatend(arr);
    cout<<"The array after deletion is "<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}