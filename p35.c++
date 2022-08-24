#include <iostream>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
    int count;
    int min = input[0];
    for(int i=0; i<size; i++){
        if(min > input[i]){
            min = input[i];
            count = i;
        }
    }
    return count;
}

int main()
{

	int t;
	cin >> t;
	while (t--)
	{

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}