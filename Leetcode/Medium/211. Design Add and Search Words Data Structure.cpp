#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Trie
struct Node
{
 Node *links[26];
 bool flag = false;

 bool containsKey(char ch)
 {
  return (links[ch - 'a'] != NULL);
 }

 void put(char ch, Node *node)
 {
  // char in current trie pointing to new reference trie
  links[ch - 'a'] = node;
 }

 Node *get(char ch)
 {
  return links[ch - 'a'];
 }

 void setEnd()
 {
  flag = true;
 }

 bool isEnd()
 {
  return flag;
 }
};

class WordDictionary
{
private:
 Node *root;

public:
 WordDictionary()
 {
  root = new Node();
 }

 void addWord(string word)
 {
  // dummy variable initially pointing to root
  Node *node = root;

  for (int i = 0; i < word.size(); i++)
  {
   // check if word[i] exists in current reference trie we are at
   if (!node->containsKey(word[i]))
   {
    node->put(word[i], new Node());
   }

   // moves to the new reference trie
   node = node->get(word[i]);
  }
  // set the flag to last reference trie to true
  node->setEnd();
 }

 bool searchHelper(string word, Node *node)
 {
  for (int i = 0; i < word.size(); i++)
  {
   if (word[i] == '.')
   {
    // . can be matched with any character, so we have to try all 26 possibilities and if any character exists in curr reference trie we see whether we can find the remaining word with that possibility, if not we move ahead and try others
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
     if (node->containsKey(ch))
     {
      if (searchHelper(word.substr(i + 1), node->get(ch)))
      {
       return true;
      }
     }
    }
    // . can be matched with any character, but if no character exists we return false
    return false;
   }
   else
   {
    if (!node->containsKey(word[i]))
    {
     return false;
    }
    node = node->get(word[i]);
   }
  }
  return node->isEnd();
 }

 bool search(string word)
 {
  return searchHelper(word, root);
 }
};