#include <iostream>
#include <string>
using namespace std;

void printKeypad_help(int num, string output){
    if (num == 0){
        cout<<output<<endl;
        return;
    }
    string s[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string input = s[num % 10];
    for(int i=0; i<input.size(); i++){
        printKeypad_help(num/10, input[i] + output);
    }
}

void printKeypad(int num){
    printKeypad_help(num, "");   
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
