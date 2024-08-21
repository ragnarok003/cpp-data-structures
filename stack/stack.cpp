#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
    Node *head;

public:
    Stack()
    {
        head = NULL;
    }
    void push(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;

        newNode->next = head;
        head = newNode;
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            cout << "Popped element = " << head->data << endl;
            Node *del = head;
            head = head->next;
            delete (del);
        }
    }

    int top()
    {
        if (head == NULL)
        {
            cout << "Stack Underflow" << endl;
        }
        else{
            return head->data;
        }
    }
};
int main()
{
    Stack list;

    list.pop();

    cout<<"Pushing element: "<<10<<endl;
    list.push(10);
    cout<<"Pushing element: "<<20<<endl;
    list.push(20);
    cout<<"Pushing element: "<<30<<endl;
    list.push(30);

    cout << "Top of stack : "<<list.top()<<endl;
    list.pop();
    list.pop();
    list.pop();
    list.pop();

    return 0;
}