#include <iostream>

using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *prev;
};

class DoublyLinkedList
{
   Node *head;
   Node *tail;

public:
   int lenght = 0;
   DoublyLinkedList()
   {
      head = NULL;
      tail = NULL;
   }

   void addFirst(int val)
   {
      Node *newNode = new Node();
      newNode->data = val;
      newNode->prev = NULL;
      
      if (head== NULL)
      {
         newNode->next = NULL;
         head = newNode;
         tail=newNode;
      }
      else{
         newNode->next=head;
         head->prev=newNode;
         head=newNode;
      }
      lenght++;
   }
   void addLast(int val)
   {
      Node *newNode = new Node();
      newNode->data = val;

      newNode->next = NULL;
      newNode->prev=tail;
      tail->next=newNode;
      tail=newNode;
      lenght++;
   }

   void print()
   {
      Node *temp = head;
      while (temp != NULL)
      {
         cout << temp->data << "-";
         temp = temp->next;
      }
   }
   void printRev()
   {
      Node *temp = tail;
      while (temp != NULL)
      {
         cout << temp->data << "-";
         temp = temp->prev;
      }
   }
};
int main()
{
   DoublyLinkedList list;

   cout << "Inserting Element: " << 40 << endl;
   list.addFirst(40);
   cout << "Inserting Element: " << 30 << endl;
   list.addFirst(30);
   cout << "Inserting Element: " << 20 << endl;
   list.addFirst(20);
   cout << "Inserting Element: " << 10 << endl;
   list.addFirst(10);
   cout << "Inserting Element: " << 50 << endl;
   list.addLast(50);
   cout << "Inserting Element: " << 70 << endl;
   list.addLast(70);
   cout << "Inserting Element: " << 80 << endl;
   list.addLast(80);
   cout << "Inserting Element: " << 90 << endl;
   list.addLast(90);
   list.print();
   list.printRev();

   return 0;
}
