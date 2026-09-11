class Solution {
public:
    int totalNumbers(vector<int>& a) {
        int n = a.size();
        int cnt = 0;
        set<int>s;
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++) {
              
                for(int k = 0; k < n; k++) {
                    if(i==j || i==k || j==k) continue;
                    if(a[i] == 0) continue;
                    int num = a[i]*100 + a[j]*10+a[k];
                    if(num%2 == 0) s.insert(num);
                }
            }
        }
        
        return s.size();        
    }
};