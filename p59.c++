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
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}
int length(Node * head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head -> next;
    }
    return count;
}
Node *appendLastNToFirst(Node *head, int n)
{
    Node * p = head;
    Node * q = head;
    for(int i=1; i<length(head) - n; i++){
        p=p->next;
    }
    for(int i=1; i<length(head); i++){
        q=q->next;
    }
    q->next = head;
    head = p->next;
    p->next = NULL;

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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}