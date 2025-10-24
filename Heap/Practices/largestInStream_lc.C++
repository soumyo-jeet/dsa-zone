class KthLargest {
    priority_queue<int, vector<int>, greater<int>> stream;
    int t;
public:
    KthLargest(int k, vector<int>& nums) {
        t = k;
        if(nums.size() == 0) return;
        for(int i = 0; i< k && i < nums.size(); i++)
        {
            stream.push(nums[i]);
        }

        for(int j = k; j < nums.size(); j++)
        {
            if(nums[j] > stream.top())
            {
                stream.pop();
                stream.push(nums[j]);
            }
        }
    }
    
    int add(int val) {
        if(stream.size() < t)
        {
            stream.push(val);
        }
        else if(val > stream.top())
        {
            stream.pop();
            stream.push(val);
        }
        if(stream.size() == t) return stream.top();
        return -1;
    }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


// https://leetcode.com/problems/kth-largest-element-in-a-stream/