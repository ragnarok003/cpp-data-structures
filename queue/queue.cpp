#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
    Node *front, *rear;

public:
    int length = 0;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;

        newNode->next = NULL;

        if (front == NULL && rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        length++;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Empty queue" << endl;
            return;
        }
        else
        {
            cout << "Dequeue Element = " << front->data << endl;

            Node *del = front;
            front = front->next;

            if (front == rear)
            {
                rear = NULL;
            }

            delete (del);
        }
        length--;
    }
};

int main()
{
    Queue list;

    list.dequeue();

    cout << "Enqueuing element: " << 10 << endl;
    list.enqueue(10);
    cout << "Enqueuing element: " << 20 << endl;
    list.enqueue(20);
    cout << "Enqueuing element: " << 30 << endl;
    list.enqueue(30);
    cout << "Queue length: " << list.length << endl;
    list.dequeue();
    list.dequeue();
    list.dequeue();
    list.dequeue();

    return 0;
}