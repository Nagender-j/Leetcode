class Solution {
public:
    int findMin(vector<int>& nums) {
        int rotatedIdx = getRotatedIdx(nums);
        
       
        return nums[rotatedIdx];
    }

        int getRotatedIdx(vector<int> &a) {
        int low = 0, high = a.size()-1;
        int n = a.size();
        /*
         intuition 
         [4,5,6,7,0,1,2],
         4 to 7 is sorted -> first half
         0 to 2 is sorted -> second half
         but 0 is min of left and right,
         so if a[mid] > a[high] then mid is first half
         else if a[mid] < a[high] then mid is in second half
        
        */
        
        while(low <= high) {
            int mid = low +(high-low)/2;
            if(a[mid] <= a[(mid+1)%n] && a[mid] < a[(mid-1+n)%n]) {
                return mid;
            } else if(a[mid] > a[high]) {
                low = mid+1;
            } else  {
                high = mid-1;
            }
        
        
        }

        // it comes here if array has duplicates and it couldn't optimally eliminate search space
        for(int i = 0 ; i < n; i++) {
            if(a[i] <= a[(i+1)%n] && a[i] < a[(i-1+n)%n]) {
                return i;
            } 
        }

        
        return 0;
    }
};