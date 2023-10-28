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
void insertAtTail(node* &head,int val){// we are having reference of head pointer here because we are gonna change Linked List in this function
    node* newnode = new node(val);
    if(head==NULL){
        head = newnode;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void searching(node* head,int val){
    node* curr = head;
    if(head==NULL){
        cout<<"The given Linked list is empty"<<endl;
        return;
    }
    while(curr!=NULL){
        if(curr->data==val){
            cout<<"The element is present in the linked list"<<endl;
            return;
        }
        curr= curr->next;
    }
    cout<<"The element is not present in the linked list"<<endl;
}
int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    searching(head,3);
    return 0;
}