#include <iostream>
#include<stack>
#include <vector>
using namespace std;


vector<int> nextGreatertoright(const vector<int>& arr) {
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
    vector<int> ans1 = nextGreatertoright(arr);
    cout<<"The next Greater to right elements in array are: "<<endl;
	for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " -> " << ans1[i] << endl;
    }
    vector<int> ans2 = nextGreaterToLeft(arr);
    cout<<"The next Greater to left elements in array are: "<<endl;
	for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " -> " << ans2[i] << endl;
    }
    vector<int> ans3 = nextSmallerToRight(arr);
    cout<<"The next Smaller to right elements in array are: "<<endl;
	for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " -> " << ans3[i] << endl;
    }
    vector<int> ans4 = nextSmallerToLeft(arr);
    cout<<"The next Smaller to left elements in array are: "<<endl;
	for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " -> " << ans4[i] << endl;
    }
    return 0;
}
