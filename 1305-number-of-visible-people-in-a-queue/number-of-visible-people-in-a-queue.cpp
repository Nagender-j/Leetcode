class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>s;
        int n = heights.size();
        vector<int>res(n);
        for(int i = n-1; i >=0 ; i--) {
            int cnt = 0;
            while(s.size() > 0 && s.top() <= heights[i]) {
                s.pop();
                cnt++;
            }

            if(s.size() == 0) {
                res[i] = cnt;
            } else {
                res[i] = cnt+1;
            }
            s.push(heights[i]);
        }

        return res;

    }
};