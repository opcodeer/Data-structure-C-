#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL;
    }
};
void deleteNthnode(node* &head, int n) {
    if(head == NULL) {
        cout << "List is empty. Deletion is not possible." << endl;
        return;
    }

    if (n == 0) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node* current = head;
    int count = 0;

    while (current != NULL && count < n - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL) {
        cout << "Invalid position for deletion." << endl;
        return;
    }

    node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void printList(node* head) {
    node* current = head;
    while (current != NULL) {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    int n = 2; // Position of the node to delete

    cout << "Original List:" << endl;
    printList(head);

    deleteNthnode(head, n);

    cout << "List after deleting node at position " << n << ":" << endl;
    printList(head);

    return 0;
}
