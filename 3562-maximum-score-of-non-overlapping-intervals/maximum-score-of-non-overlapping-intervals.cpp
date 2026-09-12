struct item {
    int l, r, wt, idx;
};

struct Result {
    long long wt = 0;
    vector<int> indices;
};

class Solution {
public:
    vector<int>res;
    long long gwt = 0 ;
    vector<vector<Result>> dp;
    Result NEG_RESULT = {-1, {}};
    Result solve(int i, int k, vector<item>& a) {
        Result result;
        if(k  == 0 || i >= a.size()) {
            return result;
        }

        if(dp[i][k].wt != -1) {
            return dp[i][k];
        }

        Result notTake = solve(i+1, k, a);
       
       // take
        Result take = solve(getNextPossibleIdx(i, a), k-1, a);
        
        take.wt += a[i].wt;
        take.indices.push_back(a[i].idx);

        result = takeMaxOf(notTake, take);

        return dp[i][k] = result;

    }

    Result takeMaxOf(Result a, Result b) {
        sort(a.indices.begin(), a.indices.end());
        sort(b.indices.begin(), b.indices.end());
        
        if(a.wt > b.wt) return a;
        else if(a.wt < b.wt) return b;
        
        return a.indices < b.indices ? a : b;
    }

    // string getStr(item i) {
    //     string s = "";
    //     s += " l : " +to_string(i.l);
    //     s += " r : " +to_string(i.r);
    //     s += " wt : " +to_string(i.wt);
    //     s += " idx : " +to_string(i.idx);

    //     return s;
        
    // }
    int getNextPossibleIdx(int i, vector<item> &a)  {
        int low = i+1, high = a.size()-1;
        int res = a.size();
        while(low <= high) {
            int mid = low +(high-low)/2;
            if(a[mid].l > a[i].r) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        // cout<<"i : "<<i <<" item : "<<getStr(a[i]) <<" this is : "<< res <<endl;
        return res;
    }


    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<item>a;
        for(int i =0 ; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }
        sort(a.begin(), a.end(), [&](auto p, auto q) {
           if(p.l != q.l) return p.l < q.l;
           else if(p.r != q.r) return p.r < q.r;
           return p.wt > q.wt; 
        });
        int k = 4;
        dp = vector<vector<Result>>(n+1, vector<Result>(k+1, NEG_RESULT));
        Result result = solve(0, 4, a);

        return result.indices;
        
        
    }
};