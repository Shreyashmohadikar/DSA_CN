#include<iostream>
using namespace std;
int swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;

}
int partition(int input[], int start, int end){
     
    // int count = 0;
    int pivot = input[end];
    int i = start - 1;
    int j = end;
    for(int i = start + 1; i <= end; i++){
        if(input[i] < pivot){
            count++;
        }
    }
    int temp = input[count];
    input[count] = pivot;
    pivot = temp;


    
    if(input[i] <= pivot){
        i++;
    }
    else if(input[j] > pivot){
        j++;
    }
    else{
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
    return start;
}

void quick_Sort(int input[], int start, int end){
    if(start > end){
        return;
    }
    int pivot = partition(input, start, end);
    quick_Sort(input, start, pivot - 1);
    quick_Sort(input, pivot + 1, end);
}

void quickSort(int input[], int size) {
    quick_Sort(input, 0, size - 1);
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


