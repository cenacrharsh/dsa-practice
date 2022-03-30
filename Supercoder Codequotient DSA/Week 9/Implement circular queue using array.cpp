#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class QueueArray
{
 const int SIZE = 4;
 int front = -1;
 int rear = -1;
 int *queue;

public:
 QueueArray()
 {
  queue = new int[SIZE];
 }
 void enQueue(int data);
 int deQueue();
};

// class QueueArray{
//   const int SIZE = 4; // SIZE of queue queueay
//   int front = -1; // front variable
//   int rear = -1; // rear variable
//   int *queue; // queue queueay
//   public:
//   	QueueArray() // constructor
//   	void enQueue(int data); // add data to the queue
//   	int deQueue(); // remove data from the queue
// };
// The above declaration is already done. Complete the function given below.

//> Function to create Circular queue
void QueueArray::enQueue(int value)
{
 if ((front == 0 && rear == SIZE - 1) ||
     (rear == (front - 1) % (SIZE - 1)))
 {
  return;
 }
 else if (front == -1) /* Insert First Element */
 {
  front = rear = 0;
  queue[rear] = value;
 }
 else if (rear == SIZE - 1 && front != 0)
 {
  rear = 0;
  queue[rear] = value;
 }
 else
 {
  rear++;
  queue[rear] = value;
 }
}

//> Function to delete element from Circular Queue
int QueueArray::deQueue()
{
 if (front == -1)
 {
  return -1;
 }

 int data = queue[front];
 queue[front] = -1;
 if (front == rear)
 {
  front = -1;
  rear = -1;
 }
 else if (front == SIZE - 1)
  front = 0;
 else
  front++;

 return data;
}

int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  int n;
  cin >> n;
  QueueArray *queue = new QueueArray();
  while (n--)
  {
   int choice;
   cin >> choice;
   if (choice == 1)
   {
    int data;
    cin >> data;
    queue->enQueue(data);
   }
   else if (choice == 2)
   {
    cout << queue->deQueue() << ' ';
   }
  }
  cout << endl;
 }
 return 0;
}