// Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
// Note: Array A can contain duplicate elements as well.
#include <iostream>
using namespace std;

#include <unordered_map>
int pairSum(int *input, int n) {
  // Write your code here
  unordered_map<int, int> m;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (m[input[i]] == 0)
      m[input[i]] = 1;
    else
      m[input[i]] += 1;
    if (m[-input[i]]) {
      count = count + m[-input[i]];
      if (input[i] == 0)
        count--;
    }
  }
  return count;
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}