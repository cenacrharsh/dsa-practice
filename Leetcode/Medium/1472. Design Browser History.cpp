#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=mG3KLugbOdc&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=29

//! Using Doubly Linked List

class DLLNode
{
public:
    string data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(string url)
    {
        data = url;
        next = NULL;
        prev = NULL;
    }
};

class BrowserHistory
{
    DLLNode *currentPage;

public:
    //! O(1)
    BrowserHistory(string homepage)
    {
        currentPage = new DLLNode(homepage);
    }

    //! O(Steps)
    void visit(string url)
    {
        DLLNode *newPage = new DLLNode(url);
        currentPage->next = newPage; //* all the forward nodes are lost and forward history is cleared;
        newPage->prev = currentPage;
        currentPage = currentPage->next;
    }

    //! O(Steps)
    string back(int steps)
    {
        while (steps--)
        {
            if (currentPage->prev)
            {
                currentPage = currentPage->prev;
            }
            else
            {
                break;
            }
        }
        return currentPage->data;
    }

    //! O(Steps)
    string forward(int steps)
    {
        while (steps--)
        {
            if (currentPage->next)
            {
                currentPage = currentPage->next;
            }
            else
            {
                break;
            }
        }
        return currentPage->data;
    }
};
