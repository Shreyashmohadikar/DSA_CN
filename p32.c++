#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[]){
    if (num == 0 || num == 1){
        output[0] = "";
        return 1;
    }
    int last_digit = num%10;
    int prev_digit = num/10;
    int smallOutputSize = keypad(prev_digit, output);
    string input;
    switch(last_digit){
        case 2: input = "abc";
            break;
        case 3: input = "def";
            break;
        case 4: input = "ghi";
            break;
        case 5: input = "jkl";
            break;
        case 6: input = "mno";
            break;
        case 7: input = "pqrs";
            break;
        case 8: input = "tuv";
            break;
        case 9: input = "wxyz";
            break;
        
    }
    int ans_size = smallOutputSize * input.size();
    string temp[ans_size];
    int k=0;
    for(int i=0; i<smallOutputSize; i++){
        for(int j=0; j<input.size(); j++){
            temp[k++] = output[i] + input[j];
        }
    }
    for(int i = 0; i<ans_size; i++){
        output[i] = temp[i];
    }

    return ans_size;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
