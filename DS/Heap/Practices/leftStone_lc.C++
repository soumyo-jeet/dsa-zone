class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // max heap (priority queue)
        priority_queue <int> pq;

        for(int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }

        while(pq.size() > 1)
        {
            int stone = pq.top();
            pq.pop();
            stone -= pq.top();
            pq.pop();

            if (stone > 0) pq.push(stone);
        }

        if (!pq.empty()) return pq.top();
        return 0;
    }
};

// https://leetcode.com/problems/last-stone-weight/