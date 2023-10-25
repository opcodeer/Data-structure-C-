#include <iostream>
using namespace std;
class node{
    public:
       int data;
       node* next;
       node* prev;
       node(int val){
          data = val;
          next = NULL;
          prev = NULL;
       }
};
void insertAthead(node *&head,int val){
    node* newnode = new node(val);
    newnode->next=head;
    if(head!=NULL) head->prev = newnode;// this case is added because if head is NULL then we cannot access the prev of our head and it will give errors.
    head = newnode;
}
void insertAtTail(node *&head,int val){
    node* newnode  = new node(val);
    if(head==NULL){
        insertAthead(head,val);
        return;
    }
    node* currnode = head;
    while(currnode->next!=NULL){
        currnode = currnode->next;
    }
    currnode->next = newnode;
    newnode->prev = currnode;
}
void display(node *head){
    node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void deleteAthead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deletion(node* &head,int pos){
    if(pos==1){
        deleteAthead(head);
        return;
    }
      node* temp = head;
      int count = 1;
      while(temp!=NULL&&count!=pos){
          temp = temp->next;
          count++;
      }
      temp->prev->next = temp->next;
      if(temp->next!=NULL) temp->next->prev = temp->prev;
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
    // insertAthead(head,6);
    // display(head);
    deletion(head,5);
    display(head);

    return 0;
}