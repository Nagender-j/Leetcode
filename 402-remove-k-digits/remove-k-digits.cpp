class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for(char c : num) {
            while(res.size() > 0 && res.back() > c && k) {
                res.pop_back();
                k--;
            }

            res.push_back(c);
        }

         while(res.size() > 0 && k) {
                res.pop_back();
                k--;
            }
        int i = 0;
        while(i < res.size() && res[i] == '0') {
            i++;
        }

        // cout<< res<<endl;
        res = res.substr(i);
        if(res == "") res = "0";
        return res;
    }
};