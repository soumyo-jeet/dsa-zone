class Solution {
  public:
    int minCost(vector<int>& arr) {
        if(arr.size() == 1) return 0;
        
        // Min heap creation of the array
        priority_queue <int, vector<int>, greater <int>> pq;
        
        for(int i = 0; i < arr.size(); i++)
        {
            pq.push(arr[i]);
        }
        
        int cost = 0;
        
        while(pq.size() > 1)
        {
            int rope = pq.top();
            pq.pop();
            rope += pq.top();
            pq.pop();
            
            cost += rope;
            pq.push(rope);
        }
        
        return cost;
    }
}; 


/* https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1 */