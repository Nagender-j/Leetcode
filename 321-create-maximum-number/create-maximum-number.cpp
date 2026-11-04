class Solution {
public:
    vector<int>res;
void merge(vector<int> a, vector<int> b) {
    int m = a.size(), n = b.size();

    vector<int> temp;
    int i = 0, j = 0;

    while(i < m && j < n) {

        // Compare remaining suffixes
        bool bGreater = lexicographical_compare(
            a.begin() + i, a.end(),
            b.begin() + j, b.end()
        );

        if(bGreater) {
            temp.push_back(b[j++]);
        } else {
            temp.push_back(a[i++]);
        }
    }

    while(i < m) {
        temp.push_back(a[i++]);
    }

    while(j < n) {
        temp.push_back(b[j++]);
    }

    // Compare with current maximum
    if(res.empty() ||
       lexicographical_compare(
           res.begin(), res.end(),
           temp.begin(), temp.end()
       )) {
        res = temp;
    }
}
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        for(int i = 0; i <= m; i++) {
            int cntFromNums1 = i, cntFromNums2 = k - i;
            if(nums2.size() < cntFromNums2) {
                continue;
            }
            
            // cout<<" printing a : b for cntFromNums1 : "<< cntFromNums1 << " and cntFromNums2 : "<< cntFromNums2<<endl; 
            vector<int> a = getIelementsFrom(nums1, cntFromNums1), b =  getIelementsFrom(nums2, cntFromNums2);
            cout<<"sizes of a b :"<<a.size() << " "<<b.size()<<endl;
            print(a);
            print(b);
            
            merge(a,b);
        }

        return res;
    }

    void print(vector<int> &a) {
        for(int i : a) {
            cout<<i<<" ";
        }

        cout<<endl;
    }

    vector<int> getIelementsFrom(vector<int> &a, int cnt) {
        vector<int> temp;
        int n = a.size();
        int k = n - cnt; // i need to delete n-i elements from a to take i candidates;
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