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
void deleteAthead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}
void deleteAtTail(node* &head){
    if(head==NULL) return;
    if(head->next==NULL) deleteAthead(head);
    node* curr = head;
    while(curr->next->next!=NULL){
        curr = curr->next;
    }
    node* todelete = curr->next;
    curr->next = NULL;
    delete todelete;
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
    deleteAtTail(head);
    cout<<"The linked list after deletion: "<<endl;
    display(head);
    return 0;
}