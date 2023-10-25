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
void deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAthead(head);
        return;
    }
    node* temp = head;
    node* curr = head->next;
    while(curr->data!=val){
        curr = curr->next;
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = curr->next;
    delete todelete;
}
int getsize(node* &head){
    node* temp = head;
    if(head==NULL) return 0;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
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
void deleteAtPosition(node* &head, int position) {
    if (head == nullptr) {
        cout << "List is empty. Deletion is not possible." << endl;
        return;
    }

    if (position == 0) {
        // Delete the first node
        node* temp = head;
        head = head->next;
        delete temp;
    } else {
        node* current = head;
        int currentPos = 0;

        while (current != nullptr && currentPos < position - 1) {
            current = current->next;
            currentPos++;
        }

        if (current != nullptr && current->next != nullptr) {
            node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            cout << "Invalid position for deletion." << endl;
        }
    }
}
void insertAtPosition(node* &head, int data, int position) {
    node* newnode = new node(data);
    newnode->data = data;
    newnode->next = nullptr;

    if (position == 0) {
        newnode->next = head;
        head = newnode;
    } else {
        node* current = head;
        int currentPos = 0;

        while (current != nullptr && currentPos < position - 1) {
            current = current->next;
            currentPos++;
        }

        if (current != nullptr) {
            newnode->next = current->next;
            current->next = newnode;
        } else {
            cout << "Invalid position for insertion." << endl;
        }
    }
}
int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAthead(head,4);
    display(head);
    deletion(head,3);// it can delete the node at end also.
    display(head);
    // searching(head,5);
    insertAtPosition(head,5,2);
    display(head);
    return 0;
}