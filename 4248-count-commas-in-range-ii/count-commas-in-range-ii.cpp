
struct item {
    long long start, total, factor;
};
#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        vector<item> a;
        a.push_back({1, 0, 0});
        a.push_back({(ll)1e3, (ll)(1e6-1e3), 1});
        a.push_back({(ll)1e6, (ll)(1e9-1e6), 2});
        a.push_back({(ll)1e9, (ll)(1e12-1e9), 3});
        a.push_back({(ll)1e12, (ll)(1e15-1e12), 4});
        a.push_back({(ll)1e15, (ll)(1e18-1e15), 5});
        a.push_back({(ll)1e18, (ll)(1e16-1e15), 6});

        long long res = 0;

        
        for(int i = 0; i < a.size() -1 ; i++) {
            ll low = a[i].start, high = a[i+1].start - 1;
            if(n>low  && n>high) {
                res += a[i].total * a[i].factor;
            } 
             else if(n >= low && n <= high){
                long long range = (n - low)+1;
                res += range*a[i].factor;
                break; 
            }
        }

        return res;

    }
};