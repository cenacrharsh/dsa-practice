#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using DLL and 2 Maps

/*
> Time Complexity: O(1)
> Space Complexity: O(1)
*/

class Node
{
public:
  int key, value, freq;
  Node *next;
  Node *prev;

  Node(int key, int value)
  {
    this->key = key;
    this->value = value;
    freq = 1;
    next = NULL;
    prev = NULL;
  }
};

class List
{
public:
  int size;
  Node *head;
  Node *tail;

  List()
  {
    size = 0;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  void insertAfterHead(Node *node)
  {
    Node *nextNode = head->next;

    node->prev = head;
    node->next = nextNode;

    head->next = node;
    nextNode->prev = node;

    size++;
  }

  void deleteNode(Node *node)
  {
    Node *nextNode = node->next;
    Node *prevNode = node->prev;

    nextNode->prev = prevNode;
    prevNode->next = nextNode;

    size--;
  }
};

class LFUCache
{
public:
  int capacity, minFreq, currSize;
  unordered_map<int, Node *> keyNodeMap;
  unordered_map<int, List *> freqListMap;

  LFUCache(int capacity)
  {
    this->capacity = capacity;
    minFreq = 0;
    currSize = 0;
  }

  void updateFreqListMap(Node *node)
  {
    //* remove the node from keyNodeMap and freqListMap
    keyNodeMap.erase(node->key);
    freqListMap[node->freq]->deleteNode(node);

    //* if the minFreq list is empty we have to inc the value of min freq
    if (node->freq == minFreq && freqListMap[node->freq]->size == 0)
    {
      minFreq++;
    }

    //* create a new list of access the list if it already exists
    List *nextHigherFreqList = new List();
    if (freqListMap.find(node->freq + 1) != freqListMap.end())
    {
      nextHigherFreqList = freqListMap[node->freq + 1];
    }

    //* inc the freq count of node and insert it into higher freq list
    node->freq += 1;
    nextHigherFreqList->insertAfterHead(node);

    //* insert the node back into keyNodeMap and insert new list into freqListMap
    keyNodeMap[node->key] = node;
    freqListMap[node->freq] = nextHigherFreqList;
  }

  int get(int key)
  {
    if (keyNodeMap.find(key) != keyNodeMap.end())
    {
      Node *node = keyNodeMap[key];
      updateFreqListMap(node);
      return node->value;
    }
    return -1;
  }

  void put(int key, int value)
  {
    if (capacity == 0)
      return;

    //* if element already exists
    if (keyNodeMap.find(key) != keyNodeMap.end())
    {
      Node *node = keyNodeMap[key];
      node->value = value;
      updateFreqListMap(node);
    }
    else
    {
      //* check if cache is full, if yes we remove the least freq used element
      if (currSize == capacity)
      {
        List *minFreqList = freqListMap[minFreq];
        keyNodeMap.erase(minFreqList->tail->prev->key); //* removing last element of min freq list from key node map
        freqListMap[minFreq]->deleteNode(minFreqList->tail->prev);
        currSize--;
      }

      //* inserting a new element, update keyNodeMap and freqListMap
      minFreq = 1;
      currSize++;

      List *newFreqList = new List();
      if (freqListMap.find(minFreq) != freqListMap.end())
      {
        newFreqList = freqListMap[minFreq];
      }
      Node *newNode = new Node(key, value);
      keyNodeMap[key] = newNode;
      newFreqList->insertAfterHead(newNode);
      freqListMap[minFreq] = newFreqList;
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */