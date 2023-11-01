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
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    node* head = NULL;
    insertAtPosition(head,1,0);
    insertAtPosition(head,2,1);
    insertAtPosition(head,3,2);
    insertAtPosition(head,5,3);
    display(head);
    insertAtPosition(head,4,3);
    cout<<"The linked list after insertion is: "<<endl;
    display(head);
    deleteAtPosition(head,3);
    cout<<"The linked list after deletion is: "<<endl;
    display(head);
    return 0;
}