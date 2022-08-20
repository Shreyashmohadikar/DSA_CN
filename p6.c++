#include<iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {
    if (size == 0){
        return -1;
    }
    if (input[size-1] == x){
        return size-1;
    }
    int output = firstIndex(input, size - 1, x);
    return output;
    
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << firstIndex(input, n, x) << endl;

}


