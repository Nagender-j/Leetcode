class Solution {
public:
    vector<int>res;
void merge(vector<int> &a, vector<int> &b) {
    int m = a.size(), n = b.size();

    vector<int> temp(m+n);
    int  k = 0;
    int i = 0, j = 0;

    while(i < m && j < n) {
        bool isAgreater = isAGreaterThanB(a, b, i, j);
        if(!isAgreater) {
            temp[k++] = b[j++];
        } else {
            temp[k++] = a[i++];
        }
    }

    while(i < m) {
        temp[k++] = a[i++];
    }
    while(j < n) {
        temp[k++] = b[j++];
    }

    if(isAGreaterThanB(temp, res, 0, 0)) {
        res = temp;
    } 
}

    bool isAGreaterThanB(vector<int>& a, vector<int>&b, int i, int j) {
        while(i < a.size() && j < b.size()) {
            if(a[i] > b[j]) return true;
            if(a[i] < b[j]) return false;

            i++;
            j++;
        }

        if(i < a.size()) return true;

        return false;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        for(int i = 0; i <= m; i++) {
            int cntFromNums1 = i, cntFromNums2 = k - i;
            if(nums2.size() < cntFromNums2) {
                continue; // no sufficient items in nums2 for this combination 
            }

            vector<int> a = getIelementsFrom(nums1, cntFromNums1), b =  getIelementsFrom(nums2, cntFromNums2);            
            merge(a,b);
        }

        return res;
    }

    vector<int> getIelementsFrom(vector<int> &a, int i) {
        vector<int> temp;
        int n = a.size();
        int k = n - i; // i need to delete n-i elements from a to take i candidates;
        // just remove k digits pattern , but looking for maxNumber instead of small
        for(int i = 0 ; i < a.size(); i++) {
            while(temp.size() && (temp.back() < a[i]) && k) {
                temp.pop_back();
                k--;
            }
            
            temp.push_back(a[i]);
        }

        while(k > 0 && temp.size()) {
            temp.pop_back();
            k--;
        }

        return temp;
    }

    
};