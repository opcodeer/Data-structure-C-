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

node* mergeSortedLists(node* list1, node* list2) {
    node* dummy = new node(0);
    node* current = dummy; 

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return dummy->next;
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
    node* list1 = new node(1);
    list1->next = new node(3);
    list1->next->next = new node(5);

    node* list2 = new node(2);
    list2->next = new node(4);
    list2->next->next = new node(6);

    node* mergedList = mergeSortedLists(list1, list2);
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
