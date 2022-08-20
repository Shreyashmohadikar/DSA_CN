#include <iostream>
using namespace std;

void printSubsets(int * input, int start_index, int input_size, int * output, int output_size){
    if(start_index == input_size){
        for(int i = 0; i < output_size; i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //start_index is not included
    printSubsets(input, start_index + 1, input_size, output, output_size);

    //start_index is included
    output[output_size] = input[start_index];
    printSubsets(input, start_index + 1, input_size, output, output_size + 1);
}

void printSubsetsOfArray(int input[], int size) {
    int output[1001];
    printSubsets(input, 0, size, output, 0);
}
int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
