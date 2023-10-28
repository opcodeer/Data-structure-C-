#include <iostream>
using namespace std;
int floorSearch(int arr[], int n, int x)
{
	if (x >= arr[n - 1])
		return n - 1;
	if (x < arr[0])
		return -1;
	for (int i = 1; i < n; i++)
		if (arr[i] > x)
			return (i - 1);

	return -1;
}
int findMax(int arr[], int low, int high)
{
 
     
    if (high == low) return arr[low];
    int mid = low + (high - low) / 2;
     if(mid==0 && arr[mid]>arr[mid+1])
       {
               return arr[mid];
       }
    if (mid < high && arr[mid + 1] < arr[mid] && mid>0 && arr[mid]>arr[mid-1]) {
        return arr[mid];
    }
    if (arr[low] > arr[mid]) {
        return findMax(arr, low, mid - 1);
    }
    else {
        return findMax(arr, mid + 1, high);
    }
}
int findMin(int arr[], int low, int high)
{
    if (arr[low] <= arr[high]) {
        return arr[low];
    }
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mid-1 >= 0 && arr[mid] < arr[mid - 1]) {
            return arr[mid];
        }
        if (arr[mid] > arr[high]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
	int arr[] = { 1, 2, 4, 6, 10, 12, 14 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 7;
	int index = floorSearch(arr, n - 1, x);
	if (index == -1) 
    cout << "Floor of " <<x<< " doesn't exist in array ";
	else 
    cout << "Floor of " << x << " is " << arr[index];
    cout<<endl;
    cout<<"The minimum element in the sorted array is "<<findMin(arr,0,n-1)<<endl;
    cout<<"The max element in the sorted array is "<<findMax(arr,0,n-1)<<endl;
	return 0;
}
