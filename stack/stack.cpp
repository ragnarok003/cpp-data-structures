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
    int length=0;
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
        length++;
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
            length--;
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
    cout << list.length<<endl;
    cout<<"Pushing element: "<<10<<endl;
    list.push(10);
    cout<<"Pushing element: "<<20<<endl;
    list.push(20);
    cout<<"Pushing element: "<<30<<endl;
    list.push(30);
    cout <<"Length of List: " <<list.length<<endl;
    cout << "Top of stack : "<<list.top()<<endl;
    list.pop();
    list.pop();
    list.pop();
    list.pop();

    return 0;
}