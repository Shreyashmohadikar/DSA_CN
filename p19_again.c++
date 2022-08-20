#include <iostream>
using namespace std;

void merge(int part1[], int size1, int part2[], int size2, int output[], int n){
    int i = 0; 
    int j = 0;
    int k = 0; 
    while(i < size1 && j < size2){
        if(part1[i] < part2[j]){
            output[k++] = part1[i++];
        }
        else{
            output[k++] = part2[j++];
        }
    }
    while(i < size1){
        output[k++] = part1[i++];
    }
    while(j < size2){
        output[k++] = part2[j++];
    }
}

void mergeSort(int input[], int size){
	if (size == 0 || size == 1){
        return;
    }
    int size1 = size/2;
    int * part1 = new int[size1];
    int size2 = size - size1;
    int * part2 = new int[size2];

    for(int i = 0; i < size1; i++){
        part1[i] = input[i];
    }
    int k = 0;
    for(int j = size1; j < size; j++){
        part2[k++] = input[j];
    }
    mergeSort(part1, size1);
    mergeSort(part2, size2);
    merge(part1, size1, part2, size2, input, size);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
