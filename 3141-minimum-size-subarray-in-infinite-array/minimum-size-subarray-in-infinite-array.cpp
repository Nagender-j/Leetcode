class Solution {
public:

    int getMinSubarray(vector<int> &a, int target) {

        if(target == 0) return 0;
        long long pfSum = 0;
        map<long long , int>mp;
        int res = 1e9;
        for(int i = 0 ; i < a.size(); i++) {
            pfSum += a[i];
            if(pfSum == target) {
                res = min(res, i+1);
            }

            if(mp.count(pfSum - target)) {
                res = min(res, i - mp[pfSum-target] );
            }
            if(mp.count(pfSum)  == 0) {
                mp[pfSum] = i;
            }

            
        }

        if(res == 1e9) return -1;

        return res;
        
    }
    int minSizeSubarray(vector<int>& nums, int target) {
        vector<int>a=nums;
        long long sum = 0;
        for(int i : nums) {
            a.push_back(i);
            sum += i;
        }

        int n = nums.size();
        int q = 0, r = target;

        if(target > sum) {
            q = target/sum;
            r = target % sum;
    
        } 

        int res = getMinSubarray(a, r);
        if(res == -1) return -1;
        
        res = n*q + res;

        return res;
    }
};