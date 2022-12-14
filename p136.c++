//You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
//If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
#include <iostream>
using namespace std;

#include<map>
int highestFrequency(int *input, int n){	 

 map <int ,int> max;
    for(int i=0 ;i<n ;i++)
    {
            max[input[i]]++;
    }
    
  
    
    int key =0;
    int value=0;
   
    for(int i=0;i<n ;i++)
    {
        if(max[input[i]] > value)
        {
            key=input[i];
            value = max[input[i]];
        }
    }
    return key;


}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}