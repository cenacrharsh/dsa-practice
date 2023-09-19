#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

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
        //* char in current trie pointing to new reference trie
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

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    /* Inserts a word into the trie */
    /* TC = O(length) */
    void insert(string word)
    {
        //* dummy variable initially poiting to root
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            //* check if word[i] exists in current reference trie we are at
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }

            //* moves to the new reference trie
            node = node->get(word[i]);
        }
        // set the flag to last reference trie to true
        node->setEnd();
    }

    /* Returns if the word is in the tire */
    /* TC = O(length of wrod) */
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        //* the flag of last reference node if true, word exists, if false word doesn't exist
        return node->isEnd();
    }

    /* Return if there is any word in the trie that starts with the prefix */
    /* TC = O(length of wrod) */
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        // if we reached this point means we have reference trie so prefix exists
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */