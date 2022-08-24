 #include <iostream>
using namespace std;

// void rotate(int *input, int d, int n)
// {
//     for(int i=0; i<d; i++){
//         int temp = input[0];
//         for(int j=1; j<n; j++){
//             input[j-1] = input[j];
//         } 
//         input[n-1] = temp;
//     }
// }

void rotate(int *input, int d, int n)
{
    int j=0;
    int * temparr = new int[d];
    for(int i=0; i<d; i++){
        temparr[i] = input[i];
    }
    for(int i=0; i<n-d; i++){
        input[i] = input[i+d];
    }
    for(int i=n-d; i<n; i++){
        input[i] = temparr[j++];
    }
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

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}