#include <iostream>
using namespace std;
#define n 20
class queue{
     int *arr;
     int front;
     int back;
     public:
        queue(){
            arr = new int[n];
            front = -1;
            back = -1;
        }
        bool isFull(){
            return back==n-1;
        }
        bool empty(){
            if(front==-1||front>back){
                return true;
            }
            return false;
        }
        void push(int x){
            if(isFull()){
                cout<<"Queue Overflow"<<endl;
                return;
            }
            back++;
            arr[back]  = x; 
            if(front==-1) front++; 
        }
        void pop(){
            if(empty()){
                cout<<"Queue Underflow"<<endl;
                return;
            }
            front++;
        }
        int peek(){
            if(empty()){
                cout<<"Queue Underflow"<<endl;
                return -1;
            }
            return arr[front];
        }
};
int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.empty()){
        cout<<q.peek()<<endl;
        q.pop();
    }
}