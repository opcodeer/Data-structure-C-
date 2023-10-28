#include <iostream>
#include<stack>
#include <vector>
using namespace std;


vector<int> findNGE(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize the result vector with -1 values

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                result[i] = arr[j];
                break;
            }
        }
    }
    return result;
}
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
vector<int> nextGreaterToLeft(vector<int>& arr) {
    vector<int> result;
    stack<int> st;

    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            result.push_back(-1); // No greater element to the left
        } else {
            result.push_back(st.top());
        }

        st.push(arr[i]);
    }

    return result;
}
int main()
{
    vector<int> arr = {11, 13, 21, 3}; // Use vector instead of an array
    vector<int> ans = findNGE(arr);
	for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " -> " << ans[i] << endl;
    }
    return 0;
}
