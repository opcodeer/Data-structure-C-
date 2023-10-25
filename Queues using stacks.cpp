#include <iostream>
#include<stack>
using namespace std;
class queue{
    stack<int>st1;
    stack<int>st2;
    public:
    bool Empty(){
       return st1.empty()and st2.empty();
    }
      void push(int x){
         st1.push(x);
      }
      int pop(){
        if(Empty()){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int topval = st2.top();
        st2.pop();
        return topval;
      }
};
int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.Empty()){
        cout<<q.pop()<<endl;
    }
    return 0;
}
