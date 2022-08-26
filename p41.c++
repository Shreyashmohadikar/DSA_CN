// #include <iostream>
// using namespace std;
// #include <algorithm>
// int maximumProfit(int arr[], int n) {
//     int sum = 0;
//     for(int i = 0; i<n ; i++){
//       sum += arr[i];
//     }
//     int avg = (sum / n);
//     sort(arr, arr + n);
//     int budget = avg;

//     for(int i=0; i<n; i++){
//         int diff = avg - arr[i];
//         if(diff < 0){
//             diff *= (-1);
//         }
//         if(diff < budget){
//             budget = arr[i];
//         }
//     } 
//     int greater = 0;
//     for(int i=0; i<n; i++){
//         if(arr[i] >= budget){
//             greater++;
//         }
//     }
//     cout<<budget<<endl;
//     return (greater * budget);
// }

// int main() {
//     int n ,*input,i,*cost;
//     cin>>n;
//     input = new int[n];
//     for(i = 0;i < n;i++)
//         cin>>input[i];
    
//     cout << maximumProfit(input, n) << endl;
    
// }


#include <iostream>
using namespace std;
#include <algorithm>
int maximumProfit(int arr[], int n) {
    sort(arr, arr + n);
    int profit = arr[0] * n;
    for(int i=1; i<n; i++){
        if(arr[i] * (n-i) > profit){
            profit = arr[i] * (n-i);
        }
    }
    return profit;
}

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
