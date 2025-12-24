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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode *>>,
                       greater<pair<int, ListNode *>>>
            pq;
        ListNode *head = new ListNode(-1), *curr = head;

        // leave all the heads into a minheap
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL)
                continue;
            pq.push({lists[i]->val, lists[i]});
        }

        while (!pq.empty()) {
            // get the minimum pair
            auto pr = pq.top();
            pq.pop();
            // add the minimum node
            curr->next = pr.second;
            // push the next of the minimum node
            if (pr.second->next != NULL) {
                pq.push({pr.second->next->val, pr.second->next});
            }
            curr = curr->next;
        }

        curr->next = NULL;
        return head->next;
    }
};