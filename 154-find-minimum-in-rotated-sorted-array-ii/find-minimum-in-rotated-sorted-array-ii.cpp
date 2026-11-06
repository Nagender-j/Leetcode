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
            if(a[mid] < a[high]) {
                high = mid;
            } else if(a[mid] > a[high]) {
                low = mid+1;
            } else  {
                high--;
            }
        
        
        }
        
        return low;
    }
};