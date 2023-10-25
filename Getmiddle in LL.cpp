#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

node* findMiddle(node* head) {
    if (head == NULL) {
        return NULL;
    }

    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    node* middle = findMiddle(head);

    if (middle != NULL) {
        cout << "The middle element is: " << middle->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}
