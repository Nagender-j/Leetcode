class Solution {
public:
    unordered_map<int,int> primePosition;
    int MOD = 1e9+7;
    int dp[31][1<<10];
    unordered_map<int,int> freq;
    int solve(int i, vector<int>& nums, int mask) {
        if(i == 0) {
            if(mask != 0)
                return 1;
            return 0;
        }

       if(dp[i][mask] != -1) return dp[i][mask];
        long long ways = 0;
        pair<bool, vector<int>> valid = isValid(nums[i-1], mask);
        if(valid.first) {
          
            vector<int> primes = valid.second;
            int newMask = setAllPrimesPositions(mask, primes);
            ways +=  solve(i-1, nums, mask);
            ways += freq[nums[i-1]] *1LL* solve(i-1, nums, newMask);
        } else {
            ways =  solve(i-1, nums, mask);
        }

        ways %= MOD;

        return dp[i][mask] = ways;
    }
    /*
    2 3 5 7 11 13 17 19 23 29
    */

    pair<bool, vector<int>> isValid(int num, int mask) {
        pair<bool, vector<int>> res;
        vector<int> primes;
        for(auto &[prime, pos] : primePosition) {
            int cnt = 0;
            if(num%prime != 0) continue;
            while(num%prime == 0) {
                cnt++;
                num/=prime;
            }
            int ppos = primePosition[prime];
            int isTaken = (mask & (1<<ppos)) != 0;
            if(cnt > 1 || isTaken) return {false, {}};

            primes.push_back(prime);
        }

        return {true, primes};

    }
    int setAllPrimesPositions(int mask, vector<int>&primes) {
        int newMask = mask;
        for(int &p : primes) {
            int pos = primePosition[p];
            newMask |= (1<<pos);
        }

        return newMask;
    }
    vector<int> getPrimes(int num) {
        vector<int>primes;
        for(auto [prime, pos] : primePosition) {
            int isFactor = 0;
            while(num%prime == 0) {
                isFactor =1;
                num/=prime;
            }

            if(isFactor) primes.push_back(prime);
        }

        return primes;
    }
    int numberOfGoodSubsets(vector<int>& a) {
        // memset(dp, -1, sizeof(dp));
        int position = 0;
        for(int i = 2; i <= 30; i++) {
            int div = 0;
            for(int j = 2; j<=i; j++) {
                if(i%j == 0) {
                    div++;
                }
            }

            if(div == 1) {
                primePosition[i] = position++;
            }
        }

        set<int>temp;
        int cntOfOne=0;
        for(int i : a) {
            if(i == 1) {
                cntOfOne++;
            } else {
                temp.insert(i);
                freq[i]++;
            }
        }

        vector<int> nums(temp.begin(), temp.end());

        memset(dp, -1, sizeof(dp));
        long long res = solve(nums.size(), nums, 0);
        
        for(int i = 0 ; i < cntOfOne; i++) {
            res *= 2;
            res %= MOD;
        }

        return res;
    }
};