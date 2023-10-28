#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> s;
    int minEle;

public:
    MinStack() {
        minEle = INT_MAX; // Initialize minEle to a maximum value
    }

    void getMin() {
        if (s.empty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Minimum Element in the stack is: " << minEle << endl;
        }
    }

    void peek() {
        if (s.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        int t = s.top();

        cout << "Top Most Element is: ";
        (t < minEle) ? cout << minEle : cout << t;
    }

    void pop() {
        if (s.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top Most Element Removed: ";
        int t = s.top();
        s.pop();
        if (t < minEle) {
            cout << minEle << endl;
            minEle = 2 * minEle - t;
        } else {
            cout << t << endl;
        }
    }

    void push(int x) {
        if (s.empty()) {
            minEle = x;
            s.push(x);
            cout << "Number Inserted: " << x << endl;
            return;
        } else if (x < minEle) {
            s.push(2 * x - minEle);
            minEle = x;
        } else {
            s.push(x);
        }

        cout << "Number Inserted: " << x << endl;
    }
};

int main() {
    MinStack s;

    // Function calls
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();

    return 0;
}
