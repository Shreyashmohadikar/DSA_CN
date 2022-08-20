#include<iostream>
using namespace std;
int count(int n){
    if (n/10 == 0){
    	return 1;
    }
    int output = 1 + count(n / 10);
    return output;
}

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}


