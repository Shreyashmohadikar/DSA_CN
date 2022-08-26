#include <iostream>
using namespace std;

bool splitter(int * input, int size, int index, int left_sum, int right_sum){
    // base case
    if(index == size){
        return left_sum == right_sum;
    }
    //conditions
    if(input[index] % 5 == 0){
        left_sum += input[index];
    }
    else if(input[index] % 3 == 0){
        right_sum += input[index];
    }
    else{
        return splitter(input, size, index + 1, left_sum + input[index], right_sum) + 
                splitter(input, size, index + 1, left_sum, right_sum + input[index]);
    }
    //recursion
    return splitter(input, size, index + 1, left_sum, right_sum);
}

bool splitArray(int * input, int size) {
    splitter(input, size, 0 , 0 , 0);    
}


int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}
