#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
      node(int val){
         data = val;
         next = NULL;
      }
};
class queue{
    node* front;
    node* back;
    public:
       queue(){
        front = NULL;
        back = NULL;
       }
       bool empty(){
        return front==NULL;
       }
       void push(int x){
          node* newnode = new node(x);
          if(empty()){
            front = newnode;
            back = newnode;
          }
          back->next = newnode;
          back = newnode;
       }
       void pop(){
          if(empty()){
            cout<<"Queue Underflow"<<endl;
            return;
          }
          node* todelete = front;
          front = front->next;
          delete todelete;
       }
       int peek(){
          if(empty()){
            cout<<"No elements in queue"<<endl;
            return -1;
          }
          return front->data;
       }
       
};
int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<"The queue using linked list is: "<<endl;
    while(!q.empty()){
        cout<<q.peek()<<endl;
        q.pop();
    }
    return 0;
}