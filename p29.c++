#include <iostream>
#include <string.h>
using namespace std;

int char_to_int(char a){
    int i = a - '0'; 
    return i;
}
char int_to_char(int i){
    char c = 'a' + i - 1;
    return c;
}
int getCodes(string input, string output[100]) {
    if (input.size() == 0){
        output[0] = "";
        return 1;
    }
    if (input.size() == 1){
        output[0] = int_to_char(char_to_int(input[0])); 
        return 1;
    }
    string smalloutput1[100];
    string smalloutput2[100];
    int size1 = getCodes(input.substr(1), smalloutput1);
    int size2 = 0;

    if(input.size() > 1){
        if((char_to_int(input[0]) * 10 + char_to_int(input[1])) >= 10 
        && 
        (char_to_int(input[0]) * 10 + char_to_int(input[1])) <=26)
        {
            size2 = getCodes(input.substr(2), smalloutput2);
        }
    }
    int count = 0;
    for(int i=0; i<size1; i++){
        output[count++] = int_to_char(char_to_int(input[0])) + smalloutput1[i];
    }
    for(int j=0; j<size2; j++){
        output[count++] = int_to_char(char_to_int(input[0]) * 10 + char_to_int(input[1])) + smalloutput2[j];
    }
    return count;
}

int main(){
    string input;
    cin >> input;

    string output[100];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 100; i++)
        cout << output[i] << endl;
    return 0;
}
