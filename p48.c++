#include <bits/stdc++.h>
using namespace std;

int Max_num(int arr[1000]){
    int max = 0;
    for(int i=0; i<1000; i++){
        if(arr[i] < 1000 && arr[i] > max){
            max = arr[i]; 
        }
    }
    return max;
}

int main(){
    int arr[100];
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++){
        cin>>arr[i];
        if(arr[i] < 0){
            break;
        }
    }
    cout<<Max_num(arr);
}