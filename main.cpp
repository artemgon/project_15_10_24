#include "classes.h"

int main()
{
    Array<int> arr(5, 2);
    arr.Add(10);
    arr.Add(20);
    arr.Add(30);
    arr.Add(40);
    cout << "Initial Array: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    arr.InsertAt(2, 25);
    cout << "After InsertAt(2, 25): ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    arr.RemoveAt(1);
    cout << "After RemoveAt(1): ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
	return 0;
}