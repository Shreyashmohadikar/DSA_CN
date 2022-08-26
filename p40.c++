#include<iostream>
using namespace std;

bool checksequenece(char large[] , char * small) {
    bool num;
    if(large[1] == '\0' && small[1] != '\0'){
        return false;
    }
    if(large[0] == small[0] && small[1] =='\0'){
        return true;
    }
    if(large[0] != small[0] && large[1] == '\0' && small[1] == '\0'){
        return false;
    }

    if (large[0] == small[0]){
        num = checksequenece(large + 1, small + 1);
    }
    else{
        num = checksequenece(large + 1, small);
    }

    if (num == true){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
	char large[100];
	char small[100];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
