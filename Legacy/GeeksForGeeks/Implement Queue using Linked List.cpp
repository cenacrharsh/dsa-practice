#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue
{
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() { front = rear = NULL; }
};

/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

// Function to push an element into the queue.
void MyQueue::push(int x)
{
    QueueNode *newNode = new QueueNode(x);
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to pop front element from the queue.
int MyQueue ::pop()
{
    if (front == NULL)
    {
        return -1;
    }
    QueueNode *toBeDeletedNode = front;
    int element = toBeDeletedNode->data;
    front = front->next;
    delete toBeDeletedNode;
    return element;
}
