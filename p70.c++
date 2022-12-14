//Find a node in LL (recursive)

#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
int findNodeRec(Node *head, int n)
{
	if(head == NULL){
        return -1;
    }
    if(n == head->data){
        return 0;
    }
    else{
        int pos = findNodeRec(head->next, n);
        if(pos != -1){
            return 1 + pos;
        }
        else{
            return -1;
        }
    }
}
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNodeRec(head, val) << endl;
	}
}