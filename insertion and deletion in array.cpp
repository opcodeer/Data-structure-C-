#include <iostream>

using namespace std;

int main() {
    int array[100];
    int size = 0;

    cout << "Enter the number of elements in the array: ";
    cin >> size;

    if (size <= 0 || size > 100) {
        cout << "Invalid array size. Please enter a positive size up to 100." << endl;
        return 1;
    }

    cout << "Enter " << size << " elements for the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    int choice;
    cout << "Choose an operation:\n1. Insertion\n2. Deletion\nEnter 1 or 2: ";
    cin >> choice;

    if (choice == 1) {
        int element, position;
        cout << "Enter the element to insert: ";
        cin >> element;
        cout << "Enter the position to insert the element: ";
        cin >> position;

        if (position < 0 || position > size) {
            cout << "Invalid position. Insertion failed." << endl;
        } else {
            for (int i = size; i > position; i--) {
                array[i] = array[i - 1];
            }
            array[position] = element;
            size++;
        }
    } else if (choice == 2) {
        int position;
        cout << "Enter the position to delete the element: ";
        cin >> position;

        if (position < 0 || position >= size) {
            cout << "Invalid position. Deletion failed." << endl;
        } else {
            for (int i = position; i < size - 1; i++) {
                array[i] = array[i + 1];
            }
            size--;
        }
    } else {
        cout << "Invalid choice. Please enter 1 for insertion or 2 for deletion." << endl;
    }

    cout << "Updated array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
