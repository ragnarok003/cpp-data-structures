#include <iostream>

using namespace std;

class Node
{
public:
   int data;
   Node *next;
};

class LinkedList
{
   Node *head;
   Node *tail;

public:
   int length = 0;
   LinkedList()
   {
      head = NULL;
      tail = NULL;
   }
   void addFirst(int val)
   {
      Node *newNode = new Node();
      newNode->data = val;
      length++;

      newNode->next = head;
      head = newNode;
      if (head->next == NULL)
      {
         tail = newNode;
      }
   }
   void addAtPosition(int val, int pos)
   {
      Node *newNode = new Node();
      newNode->data = val;
      Node *temp = head;

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
         while (p < pos - 1)
         {
            temp = temp->next;
            p++;
         }
         newNode->next = temp->next;
         temp->next = newNode;
      }
      length++;
   }
   void addLast(int val)
   {
      Node *newNode = new Node();
      newNode->data = val;
      length++;
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
   }
   void deleteElement(int n)
   {
      Node *temp = head;
      if (head->data == n)
      {
         Node *del = temp;
         head = temp->next;
         delete (del);
         length--;
         return;
      }
      else if (tail->data == n)
      {

         while (temp->next != tail)
         {
            temp = temp->next;
            // cout << temp->data<< '-';
         }
         tail = temp;
         tail->next = NULL;
         delete (temp->next);
         length--;
         return;
      }
      else
      {
         while (temp->next != NULL)
         {
            if (temp->next->data == n)
            {
               Node *del = temp->next;
               temp->next = temp->next->next;
               delete (del);
               length--;
               return;
            }
            temp = temp->next;
         }
         throw "NOT FOUND";
      }
   }
   void print()
   {
      Node *temp = head;
      do
      {
         cout << temp->data << "\t";
         temp = temp->next;
      } while (temp != NULL);
      cout << endl;
   }
   int search(int n)
   {
      Node *temp = head;
      int c = 1;
      while (temp != NULL)
      {
         if (temp->data == n)
         {
            return c;
         }
         c++;
         temp = temp->next;
      }
      throw "Element Not Found";
   }
};

int main()
{
   LinkedList list;

   cout << "Inserting Element: " << 10 << endl;
   list.addFirst(40);
   cout << "Inserting Element: " << 20 << endl;
   list.addFirst(30);
   cout << "Inserting Element: " << 30 << endl;
   list.addFirst(20);
   cout << "Inserting Element: " << 40 << endl;
   list.addFirst(10);
   cout << "Inserting Element: " << 50 << endl;
   list.addLast(50);
   cout << "Inserting Element: " << 70 << endl;
   list.addLast(70);
   cout << "Inserting Element: " << 80 << endl;
   list.addLast(80);
   cout << "Inserting Element: " << 90 << endl;
   list.addLast(90);
   cout << list.length << endl;
   cout << "Inserting Element: " << 60 << endl;
   list.addAtPosition(60, 6);
   cout << list.length << endl;

   cout << "The LinkedList ELEMENTS ARE :" << endl;
   list.print();
   int se;
   cout << "\nEnter Search Element" << endl;
   cin >> se;
   try
   {
      cout << list.search(se) << endl;
   }
   catch (char const *s)
   {
      cout << s << endl;
   }
   int del_el;
   cout << "\nEnter element to delete ";
   cin >> del_el;
   try
   {
      list.deleteElement(del_el);
   }
   catch (char const *s)
   {
      cout << s << endl;
   }
   list.print();
   cout << list.length;
   return 0;
}