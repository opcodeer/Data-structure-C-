// Code of insertathead,deleteathead,deletion at end, insertion at end,printing and searching in the Linked list.
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
void insertAthead(node* &head,int val){
        node* newnode = new node(val);
        if(head==NULL){
            head = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
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
    insertAthead(head,1);
    insertAthead(head,2);
    insertAthead(head,3);
    display(head);
    insertAthead(head,4);
    display(head);
    deleteAthead(head);// it can delete the node at end also.
    display(head);
    return 0;
}