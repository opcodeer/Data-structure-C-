#include <iostream>
using namespace std;
int index = -1;
int len = 0;
int maxlen = 100;
void insertionatbeginning(int *arr,int ele){
    if(len>=maxlen){
        cout<<"Overflow"<<endl;
        return;
    }
    if(len==0||index==-1){
        index++;
        arr[index] = ele;
        len++;
        return;
    }
    len++;
    for(int i=len;i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = ele;
}
void deletionatbeginning(int *arr){
    if(len==0||index==1){
        cout<<"No elements to delete in array"<<endl;
    }
    for(int i=0;i<len-1;i++){
        arr[i] = arr[i+1];
    }
    len--;
}
int main()
{
    int* arr;
    insertionatbeginning(arr,1);
    insertionatbeginning(arr,2);
    insertionatbeginning(arr,3);
    insertionatbeginning(arr,4);
    insertionatbeginning(arr,5);
    cout<<"The array after insertion "<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    deletionatbeginning(arr);
    cout<<"The array after deletion is "<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}