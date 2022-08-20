#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if(n/10 == 0){
        return n;
    }
    int rem = n % 10;
    int sum = rem + sumOfDigits(n/10);
    return sum;
}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
