#include <iostream>
#include <algorithm>
using namespace std;

int tripletSum(int *A, int n, int num)
{
	sort(A,A + n);
    int i = 0;
    int j = n - 1 ;
    int count = 0;
    while (i < j)
    {
       if(A[i] + A[j] == num){
        count++;
       }         
       else if(A[i] + A[j] < num){
        i = i+1;
       }
       else{
        j = j-1;
       }
    } 
    return count;
}
// int find_sumPair( A[], n, num)
//  { 
//     Sort(A, n)
//     i = 0
//     j = n -1 
//     while (i < j)
//     {
//        if(A[i] + A[j] == num)
//          return 1
//        else if(A[i] + A[j] < num)
//          i = i+1
//        else
//          j = j-1
//     } 
//  return -1
//  }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}