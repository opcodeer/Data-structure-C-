#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
private:
    node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int data) {
        node* new_node = new node(data);
        if (top == NULL) {
            top = new_node;
        } else {
            new_node->next = top;
            top = new_node;
        }
    }

    int pop() {
        if (isEmpty()) {
            cerr << "Stack is empty." << endl;
            return -1;
        } else {
            int popped_item = top->data;
            node* temp = top;
            top = top->next;
            delete temp;
            return popped_item;
        }
    }

    int peek() {
        if (isEmpty()) {
            cerr << "Stack is empty." << endl;
            return -1;
        } else {
            return top->data;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        node* current = top;
        while (current) {
            cout << current->data << "->";
            current = current->next;
        }
        cout <<"NULL"<< endl;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.display();

    int top_element = stack.peek();
    cout << "Top element:" << top_element << endl;

    int popped_element = stack.pop();
    cout << "Popped element:" << popped_element << endl;

    stack.display();

    return 0;
}
