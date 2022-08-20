#include <iostream>
using namespace std;
#include <string.h>
#include<math.h>

int stringToNumber(char input[]) {
    int size = strlen(input);
    if (size == 1){
        return input[0] - '0';
    }
    else{
        int b = input[0] - '0';
        return (b * pow(10,size-1) + stringToNumber(input + 1));
    }
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
