//print permutations

#include <iostream>
#include <string>
using namespace std;

void FindPermutations(string output, string str){
    int size = str.size();
    if(size == 0){
        cout<<output<<endl;
    }
    else{
        for(int i=0; i<size; i++){
            FindPermutations(output + str[i], str.substr(0,i) + str.substr(i+1,size) );
        }
    }
}

void printPermutations(string input){
	FindPermutations("", input);
    	
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}