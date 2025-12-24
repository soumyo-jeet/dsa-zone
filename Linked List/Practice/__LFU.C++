#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int val, freq, key;        // value, frequency count, cache key
    Node *next, *prev;

    Node(int x, int y)
    {
        val = x;               // store value
        key = y;               // store key (IMPORTANT for eviction)
        freq = 1;              // new nodes start with frequency 1
        next = prev = NULL;
    }
};

class DLL
{
public:
    Node *head, *tail;

    DLL()
    {
        // dummy nodes to simplify insert/remove
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // insert node right after head (MRU position)
    void insert(Node *newNode)
    {
        Node *oldNext = head->next;

        head->next = newNode;
        newNode->prev = head;

        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    // remove a node from DLL
    void remove(Node *target)
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }

    // check if DLL is empty (only dummy nodes left)
    bool isEmpty()
    {
        return head->next == tail;
    }
};

class LFUCache
{
public:
    int capacity;                      // max capacity
    map<int, DLL *> freqMap;           // freq -> DLL of nodes
    map<int, Node *> keyMAp;           // key -> Node
    DLL *cache;                        // not strictly needed, kept as you had

    LFUCache(int capacity)
    {
        this->capacity = capacity;
        cache = new DLL();             // initialize owned DLL
    }

    int get(int key)
    {
        // key not present
        if (keyMAp.find(key) == keyMAp.end())
            return -1;

        Node *pos = keyMAp[key];       // fetch node
        int oldFreq = pos->freq;       // store old frequency

        // remove node from old frequency list
        freqMap[oldFreq]->remove(pos);

        // if old frequency list becomes empty, erase it
        if (freqMap[oldFreq]->isEmpty())
            freqMap.erase(oldFreq);

        // increase frequency
        pos->freq++;

        // ensure new frequency DLL exists
        if (freqMap.find(pos->freq) == freqMap.end())
            freqMap[pos->freq] = new DLL();

        // insert node into new frequency DLL (MRU)
        freqMap[pos->freq]->insert(pos);

        return pos->val;               // return stored value
    }

    void put(int key, int value)
    {
        // zero capacity edge case
        if (capacity == 0)
            return;

        // key already exists → update value + increase freq
        if (keyMAp.find(key) != keyMAp.end())
        {
            keyMAp[key]->val = value;
            get(key);                  // reuse get() logic
            return;
        }

        // cache is full → eviction required
        if (keyMAp.size() == capacity)
        {
            // lowest frequency list
            auto it = freqMap.begin();

            // LRU node inside that frequency (tail->prev)
            Node *lfuKey = it->second->tail->prev;

            // remove from key map using KEY (NOT value)
            keyMAp.erase(lfuKey->key);

            // remove from frequency DLL
            it->second->remove(lfuKey);

            // clean empty frequency list
            if (it->second->isEmpty())
                freqMap.erase(it->first);
        }

        // create new node
        Node *newNode = new Node(value, key);

        // ensure freq=1 list exists
        if (freqMap.find(1) == freqMap.end())
            freqMap[1] = new DLL();

        // insert new node
        freqMap[1]->insert(newNode);
        keyMAp[key] = newNode;
    }
};

int main()
{
    LFUCache *cache = new LFUCache(2);

    cache->put(1, 1);
    cache->put(1, 1);
    cout << cache->get(1) << endl; // 1

    cache->put(2, 2);
    cout << cache->get(2) << endl; // 2

    cache->put(3, 3);
    cout << cache->get(1) << endl; // 1
    cout << cache->get(2) << endl; // -1
    cout << cache->get(3) << endl; // 3
}
