#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextSmallerToRight(vector<int>& arr) {
    vector<int> result;
    stack<int> st;

    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            result.insert(result.begin(), -1); // No smaller element to the right
        } else {
            result.insert(result.begin(), st.top());
        }

        st.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> nseToRight = nextSmallerToRight(arr);

    cout << "Next Smaller Element to the Right :" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " -> " << nseToRight[i] << endl;
    }

    return 0;
}
