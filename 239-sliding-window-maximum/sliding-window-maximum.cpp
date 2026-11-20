class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
        
        0 ..... i-1 , i ...... n-1
        
        */

        deque<int>dq;
        
        vector<int>res;
        int i;

        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);
        for(i = k; i < nums.size(); i++) {
            int s = i-k;
            if(dq.front() == s) {
                dq.pop_front();
            }
            while(dq.size() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);

            res.push_back(nums[dq.front()]);
            
           
            
        }

        return res;
    }
};