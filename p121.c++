//Check Max-Heap
#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
  // Write your code here
  for (int i = 0; i < n; i++) {
    int leftChildIndex = 2 * i + 1;
    int rightChildIndex = 2 * i + 2;
    if (leftChildIndex < n && rightChildIndex < n &&
        (!(arr[leftChildIndex] < arr[i] && arr[rightChildIndex] < arr[i])))
      return false;
    else if (leftChildIndex < n && !(arr[leftChildIndex] < arr[i]))
      return false;
  }
  return true;
}
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}