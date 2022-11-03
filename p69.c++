#include <iostream>

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;
Node *reverseLinkedList(Node *head)
{
    // Write your code here
    if (head == NULL)
        return head;
    Node *current = head;
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    while (current != tail)
    {
        int temp = current->data;
        current->data = tail->data;
        tail->data = temp;
        if (current->next != tail)
        {
            Node *prev = current;
            while (prev->next != tail)
                prev = prev->next;
            tail = prev;
            current = current->next;
        }
        else
            current = current->next;
    }
    return head;
}
Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}