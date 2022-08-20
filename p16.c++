#include <iostream>
using namespace std;
#include <string.h>
void pairStar(char input[]) {
    
    if(input[0] == '\0'){
        return;
    }
    pairStar(input + 1);
    if (input[0] == input[1]){
        int size = strlen(input);
        input[size+1] = '\0';
        for(int i = size - 1; i >= 1; i--){
            input[i+1] = input[i];
        }
        input[1] = '*'; 
        
    }
    
}
    
int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
