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
   int length = 0;
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

      if (head == NULL)
      {
         newNode->next = NULL;
         head = newNode;
         tail = newNode;
      }
      else
      {
         newNode->next = head;
         head->prev = newNode;
         head = newNode;
      }
      length++;
   }
   int search(int val)
   {
      Node *temp = head;
      int pos = 1;
      while (temp != NULL)
      {
         if (temp->data == val)
         {
            return pos;
         }
         pos++;
         temp = temp->next;
      }
      throw "NOT FOUND";
   }
   void addLast(int val)
   {
      Node *newNode = new Node();
      newNode->data = val;

      newNode->next = NULL;
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
      length++;
   }
   void deleteElement(int n)
   {
      Node *temp_head = head;
      Node *temp_tail = tail;

      if (temp_head->data == n)
      {
         Node *del = temp_head;
         temp_head->next->prev = NULL;
         head = temp_head->next;
         delete (del);
         length --;
         return;
      }
      else if (temp_tail->data == n)
      {
         Node *del = temp_tail;
         temp_tail->prev->next = NULL;
         tail = temp_tail->prev;
         delete (del);
         length--;
         return;
      }
      else
      {
         Node *temp = head;
         while (temp->next != NULL)
         {
            if (temp->next->data == n)
            {
               Node *del = temp->next;
               temp->next->next->prev = temp;
               temp->next = temp->next->next;
               delete (del);
               length--;
               return;
            }
            temp = temp->next;
         }
      }
      throw "Not Found";
   }
   void addAtPosition(int val, int pos)
   {

      if (pos == 1)
      {
         addFirst(val);
      }
      else if (pos == length)
      {
         addLast(val);
      }
      else
      {
         int p = 1;
         Node *newNode = new Node();
         newNode->data = val;
         Node *temp = head;
         while (p < pos - 1)
         {
            temp = temp->next;
            p++;
         }
         newNode->next = temp->next;
         temp->next->prev = newNode;
         temp->next = newNode;
         newNode->prev = temp;
      }
      length++;
   }
   void print()
   {
      Node *temp = head;
      while (temp != NULL)
      {
         cout << temp->data << " ";
         temp = temp->next;
      }
      cout << endl;
   }
   void printRev()
   {
      Node *temp = tail;
      while (temp != NULL)
      {
         cout << temp->data << " ";
         temp = temp->prev;
      }
      cout << endl;
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
   list.addAtPosition(60, 6);
   cout << "Length " << list.length << endl;
   // try {
   //    cout << list.search(70);
   // }
   // catch(char const * s){
   //    cout << s;
   // }
   list.print();
   try{
      list.deleteElement(20);
   }
   catch(const char *s){
      cout << s <<endl;
   }
   list.print();
   // list.printRev();

   return 0;
}
