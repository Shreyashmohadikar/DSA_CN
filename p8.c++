#include <iostream>
using namespace std;

int multiplyNumbers(int m, int n) {
    if (m == 0 || n == 0){
        return 0;
    }
    int sum = multiplyNumbers(m, n-1);
    int mul = m + sum;
    return mul;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
