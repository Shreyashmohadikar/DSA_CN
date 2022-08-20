#include <iostream>
using namespace std;

int binarySearch_helper(int input[], int start, int end, int element){
    if(start > end){
        return -1;
    }
    else{
        int mid = (start + end) / 2;
        if(input[mid] == element){
            return mid;
        }
        else if( input[mid] < element){
            return binarySearch_helper(input, mid + 1, end,element);
        }
        else{
            return binarySearch_helper(input, start, mid - 1, element);
        }
    }
}

int binarySearch(int input[], int size, int element){
    int start = 0;
    int end = size - 1;
    return binarySearch_helper(input, start, end, element);
}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}


// def binarySearch(nums, key):
//     return binarySearch_helper(nums, key, 0, len(nums))
    
// def binarySearch_helper(nums, key, start_idx, end_idx):
//     middle_idx = (start_idx + end_idx) // 2
//     if start_idx == end_idx:
//         return None
//     if nums[middle_idx] > key:
//         return binarySearch_helper(nums, key, start_idx, middle_idx)
//     elif nums[middle_idx] < key:
//         return binarySearch_helper(nums, key, middle_idx + 1, end_idx)
//     else:
//         return middle_idx

// int binarySearch(int input[], int size, int element) {
//     int low = 0;
//     int high = size - 1;
//     if(low > high){
//         return 0;
//     }
//     else{
//         int mid = (low + high) / 2;
//         if (input[mid] == element){
//             return mid;
//         }
//         else if(element < input[mid]){
//             high = mid - 1;
//             return binarySearch(input, high - low + 1, element);
//         }
//         else if(element > input[mid]){
//             low = mid + 1;
//             return binarySearch(input,high - low, element);
//         }
//         else {
//     	    return -1;
//         }
//     }
// }