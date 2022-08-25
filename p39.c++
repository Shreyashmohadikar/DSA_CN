#include <iostream>
#include <algorithm>
using namespace std;

int pairSum(int *arr, int n, int num)
{
    sort(arr, arr + n);
    int i = 0;
    int j = n-1;
    int ans = 0;
    int k = 0;
    while(i < j){
        k = arr[i] + arr[j];
        if(k == num){
            ans++;
            i++;
            j--;
        }
        else if(k > num){ 
            j--;
        }
        else{
            i++;
        }
    }
    if(ans == 0){
        return 0;
    }
    return ans;
}


int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}