class Solution {
public:
    int search(vector<int>& nums, int target) {
        int rotatedIdx = getRotatedIdx(nums);
        
        int left = find(nums, target, 0, rotatedIdx-1);
        if(left != -1) return left;
        
        int right = find(nums, target, rotatedIdx, nums.size()-1);
        return right;
    }

    int getRotatedIdx(vector<int> &a) {
        int low = 0, high = a.size()-1;
        int n = a.size();
        
        if(n == 1) return 0;
        while(low <= high) {
            int mid = low +(high-low)/2;
            if(a[mid] < a[(mid+1)%n] && a[mid] < a[(mid-1+n)%n]) {
                return mid;
            } else if(a[mid] > a[high]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        cout<<"not found";
        return -1;
    }
    int find(vector<int> &a, int target, int low, int high) {
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(a[mid] == target) return mid;
            if(a[mid] > target) high = mid-1;
            else low = mid+1;
        }

        return -1;
    }
};