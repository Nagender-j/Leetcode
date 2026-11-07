class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int k = (m+n+1)/2;
        bool even = (m+n)%2 == 0;
        if(m == 0) {
            if(even) {
                return (double)(nums2[k-1] + nums2[k])*0.5;  
            }
            return nums2[k-1];
        } else if(n == 0) {
            if(even) {
                return (double)(nums1[k-1] + nums1[k])*0.5;
            }
            return nums1[k-1];
        }

        // i want k elements from nums1 and nums2 together

        // i will do binary search of nums1 from 0 to min(k, m) and for each mid
        // i will choose 0 to mid elements from nums1 and remaining k - mid from nums2 

        int low  = 0 , high = min(m, k);
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            int l1 = mid-1;
            int l2 = k - mid -1;
            int r1 = l1+1;
            int r2 = l2+1;

            int comp1 = -1, comp2 = -1; // compare 
            // comp1 -> l1 to r2 
            if(l1>=0 && l1 < m && r2>=0 && r2 < n) {
                if(nums1[l1] > nums2[r2]) {
                    comp1 = 0;
                } else {
                    comp1 = 1;
                }
            }
            
            // comp2 -> l2 to r1
            if(l2>=0 && l2 < n && r1 >=0 && r1 < m) {
                if(nums2[l2] > nums1[r1]) {
                    comp2 = 0;
                } else {
                    comp2 = 1;
                }
            }

            bool isValid = false;
            if(comp1 == -1) {
                if(comp2 == 1) {
                    isValid = true;
                }
            } else if(comp2 == -1) {
                if(comp1 == 1) {
                    isValid = true;
                }
            } else {
                if(comp1 == 1 && comp2 == 1) {
                    isValid = true;
                }
            }


            if(isValid) {
               int firstNum, secondNum;
               if(l1>=0 && l1 < m && l2 >=0 && l2 < n) {
                firstNum = max(nums1[l1], nums2[l2]);
               } else if(l1>=0 && l1 < m) {
                 firstNum = nums1[l1];
               } else {
                  firstNum = nums2[l2];
               }


              if(r1>=0 && r1 < m && r2 >=0 && r2 < n) {
                secondNum = min(nums1[r1], nums2[r2]);
               } else if(r1>=0 && r1 < m) {
                 secondNum = nums1[r1];
               } else {
                  secondNum = nums2[r2];
               }
               
               cout<<"mid : "<<mid<<endl;
               cout<<firstNum << " "<<secondNum<<endl;
               if((m+n)%2 == 0) {
                 return (double)(firstNum+secondNum) * 0.5;
               }

               return firstNum;

               
            } else if( comp1 == 0) {
                high = mid-1;
            } else {
                low = mid+1;
            }

            

        }

        return 0;
    }
};