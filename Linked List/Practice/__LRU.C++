#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

class LRUCache {
public:
    // dll initialisation
    class Node {
        public:
        int key, val;
        Node* prev, * next;

        Node (int k, int v)
        {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    // initialise the boundaries of the dll
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int size, capacity;
    unordered_map<int, Node*> cm;

    void addNode (Node* newNode)
    {
        Node* oldNode = head->next;

        newNode->next = oldNode;
        newNode->prev = head;
        
        head->next = newNode;
        oldNode->prev = newNode;

        size++;
    }

    void delNode (Node* target)
    {
        Node* prevTarget = target->prev;
        Node* postTarget = target->next;

        prevTarget->next = postTarget;
        postTarget->prev = prevTarget;


        size--;
    }


    LRUCache(int s)
    {
        capacity = s;
        size = 0;

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key)
    {
        if(cm.find(key)==cm.end()) return -1;
        
        // find the node
        Node* n = cm[key];
        int value = n->val;

        // delete the node
        delNode(n);

        // add the node again so that it always be next to the head
        addNode(n);
        return value;
    }

    void put(int key, int val)
    {
        // update if exists
        if(cm.find(key)!=cm.end())
        {
            // find the node from the map
            Node* n = cm[key];
            delNode(n);
        }

        // if size exceeds the capacity
        if(size == capacity)
        {
            // delete the lru key => prev node of the tail
            cm.erase(tail->prev->key);
            delNode(tail->prev);
        }


        // create the newNode, add it and record it
        Node* newNode = new Node(key, val);
        addNode(newNode);
        cm[key] = newNode; 
    }

};

int main()
{
    int s;
    cout << "Size of the LRU: ";
    cin >> s;
    LRUCache myLRU = LRUCache(s);

    string menu = "1. Put, 2. Get\nChoose one: ";
    int opt;
    cout << menu;
    cin >> opt;

    while (opt < 7)
    {
        switch (opt)
        {
        case 1:
            int k, v;
            cout << "Key: ";
            cin >> k;
            cout << "Value: ";
            cin >> v;
            myLRU.put(k, v);
            break;

        case 2:
            int key, res;
            cout << "Key: ";
            cin >> key;
            res = myLRU.get(key);
            cout << res << endl;
            break;

        default:
            break;
        }

        cout << menu;
        cin >> opt;
    }
}