#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int key;
    node* next;

    node(int key){
        this->key = key;
        next = NULL;
    }
};

class LinkedList {
public:
    node* head;

    LinkedList() : head(nullptr) {}

    void append(int key) {
        node* newnode = new node(key);
        if (head == nullptr) {
            head = newnode;
            return;
        }

        node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newnode;
    }

    void printList() {
        node* current = head;
        while (current != nullptr) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    void detectAndRemoveLoop() {
        if (head == nullptr || head->next == nullptr)
            return;

        node *slow = head, *fast = head;
        slow = slow->next;
        fast = fast->next->next;

        while (fast && fast->next) {
            if (slow == fast)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow == fast) {
            slow = head;
            if (slow == fast) {
                while (fast->next != slow)
                    fast = fast->next;
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            fast->next = nullptr;
        }
    }
};

int main() {
    LinkedList linkedList;
    linkedList.append(50);
    linkedList.append(20);
    linkedList.append(15);
    linkedList.append(4);
    linkedList.append(10);

    // Create a loop for testing
    linkedList.head->next->next->next->next->next = linkedList.head;

    linkedList.detectAndRemoveLoop();

    cout << "Linked List after removing loop" << endl;
    linkedList.printList();

    return 0;
}
