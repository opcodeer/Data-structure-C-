#include <iostream>
using namespace std;
#define n 100
class stack{
     int *arr;
     int top;
     public:
        stack(){
        arr = new int[n];
        top = -1;
    }
    bool isFull(){
        return top==n-1;
    }
    bool isEmpty(){
        return top==-1;
    }
    void push(int x){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }
    int Top(){
        if(isEmpty()){
            cout<<"No element in the stack"<<endl;
            return -1;
        }
        return arr[top];
    }
};
int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    return 0;
}