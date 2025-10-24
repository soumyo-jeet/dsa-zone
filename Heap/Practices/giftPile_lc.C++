class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // max heap
        priority_queue <int> pq;

        for(int i = 0; i < gifts.size(); i ++)
        {
            pq.push(gifts[i]);
        }

        long long gc = 0;
        while(pq.size() >= 1 && gc < k)
        {
            long long gift = pq.top();
            pq.pop();
            
            gift = sqrt(gift);
            pq.push(gift);
            gc ++;
        }

        long long rem = 0;
        while(!pq.empty())
        {
            rem += pq.top();
            pq.pop();
        }

        return rem;
    }
};


// https://leetcode.com/problems/take-gifts-from-the-richest-pile/