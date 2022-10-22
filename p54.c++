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

Node *deleteNode(Node *head, int pos)
{
    Node * curr = head;
    int i = 0;
    if(head == NULL){
        return head;
    }
    if(pos == 0){
        head = curr->next;
        delete curr;
        return head;
    }
    while( i < pos - 1 && curr->next != NULL){
        curr = curr->next;
        i++;
    }
    if(curr->next != NULL){
    //     curr->next = curr->next->next;
    //     delete curr->next;
    Node * temp = curr->next->next;
    delete curr->next;
    curr->next = temp;
    }
    return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}