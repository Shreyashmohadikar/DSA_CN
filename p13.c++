#include <iostream>
using namespace std;
#include <string.h>

void removeX(char input[]) {
    if (input[0] == '\0'){
        return;
    }
    if(input[0] == 'x'){
        int size = strlen(input);
        for(int i = 0; i < size; i++){
            input[i] = input[i+1];
        }
        removeX(input);
    }
    removeX(input + 1);
 
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
