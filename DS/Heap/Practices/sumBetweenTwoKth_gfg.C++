class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long k1, long long k2) {
        // Your code goes here
        // max heap of k2 size
        priority_queue<long long> pq;
        
        for(int i = 0; i < k2; i++)
        {
            pq.push(A[i]);
        }
        
        for(int i = k2 ; i < N; i++)
        {
            if(pq.top() > A[i]) 
            {
                pq.pop();
                pq.push(A[i]);
            }
        }
        
        int ans = 0;
        pq.pop();
        while(pq.size() > k1)
        {
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};


// https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1