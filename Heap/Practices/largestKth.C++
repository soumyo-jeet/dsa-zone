// Solution 1 : -> 
//  1. Create a maxheap with all the elemnts in the array
//  2. Each pop will disclose max element of the next iteration 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // max heap
        priority_queue <int> pq;
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        
        int ans = pq.top();
        while(!pq.empty() && k > 1)
        {
            k--;
            pq.pop();
            ans = pq.top();
        }

        return ans;
    }
};

// Solution 2 :->
//  1. Create minheap with the first k elements of the array
//  2. Iterate through the remaining part of the array
//  3. If the top of the min heap becomes lesser than the current element of the array, pop it and push the new one
//  4. Atlasat the top of the heap (with k elements) will be the kth largest 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min heap
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        
        for(int j = k ; j < nums.size(); j++)
        {
            if (pq.top() < nums[j])
            {
                pq.pop();
                pq.push(nums[j]);
            }
        }

        return pq.top();
    }
}; 