#include<iostream>
using namespace std;
int swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quickSort(int input[], int size) {
    if(size == 0 || size == 1){
        return;
    }
    int counter = 0;
    for(int i = 1; i < size; i++){
        if(input[i] < input[0]){
            counter++;
        }
    }
    swap(&input[0], &input[counter]);
    int i = 0;
    int j = size - 1;
    while(i<counter && j>counter){
        if(input[i] < input[counter]){
            i++;
        }
        else if (input[j] >= input[counter]){
            j--;
        }
        else{
            swap(&input[i],&input[j]);
            i++;
            j--;
        }
    }
    quickSort(input, counter);
    quickSort(input+counter+1,size-1-counter);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


