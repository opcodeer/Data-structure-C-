#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerToLeft(vector<int>& arr) {
    vector<int> result;
    stack<int> st;

    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            result.push_back(-1); // No smaller element to the left
        } else {
            result.push_back(st.top());
        }

        st.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> nseToLeft = nextSmallerToLeft(arr);

    cout << "Next Smaller Element to the Left: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " -> " << nseToLeft[i] << endl;
    }

    return 0;
}
