#include <iostream>
#include <string.h>
using namespace std;

bool checkPalindrome(char input[]) {
    static int i = 0;
    int S = strlen(input);

    if (i >= S){
        return true;
    }
    
    if(input[i] != input[S-i-1]){
        return false;
    }
    else{
        i++;
        checkPalindrome(input);
    }

}

// bool checkPalindrome(char input[]) {
//     int i = 0;
//     int S = strlen(input) - 1;
//     while (i < S){
//         if (input[i] != input[S]){
//             return false;
//         }
//         i++;
//         S--;
//     }
//     return true;
// }

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

// 0 - n-1
// 1 - n-1-1
// 2 - n-1-2
// i - n-1-i