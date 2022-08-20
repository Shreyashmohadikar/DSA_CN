#include <iostream>
using namespace std;
#include <string.h>

void help(string input, string output){
    if(input[0] == '\0'){
        cout<<output<<endl;
        return;
    }
    int num = input[0] - '0';
    char c = num + 'a' - 1;
    help(input.substr(1), output + c);

    if(input[1] != '\0'){
        num = num * 10 + input[1] - '0';
        //
        c = num + 'a' - 1;
        if(num>=10 && num<=26){
            help(input.substr(2), output + c);
        }
    }
    
}

void printAllPossibleCodes(string input) {
    help(input, "");
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
