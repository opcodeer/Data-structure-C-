#include <iostream>
using namespace std;
int trapRainwater(int a[], int n) {
        int left[n];
        int right[n];

        left[0] = a[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], a[i]);
        }

        right[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], a[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(left[i], right[i]) - a[i];
        }

        return ans;
    }

int main() {
    int a[] = {4, 2, 0, 3, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int b = trapRainwater(a, n);
    cout << b << endl;

    return 0;
}
