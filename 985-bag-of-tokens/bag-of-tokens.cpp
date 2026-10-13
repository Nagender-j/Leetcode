class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int power) {
        sort(a.begin(), a.end());
        // i            j
        // 100 200 300 400 
        if(a.size() == 1) return a[0] <= power;
        int i = 0, j = a.size()-1;
        int coins = 0;
        while(i <= j) {
            if(power >= a[i]) {
                power -= a[i];
                coins++;
                cout<<"increamented at i : "<<i<<endl;
                i++;
            } else {
                if(coins > 0 && i+1 < j) {
                    power += a[j];
                    coins--;
                    cout<<"decremented at j :"<<j<<endl;
                    j--;
                } else {
                    break;
                }
               
                
            }
        }

        return coins;
    }
};