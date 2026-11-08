class Solution {
public:
    bool isValid(int mid, int k, int m, int n) {
        int cntK = 0;
  
        for(int i = 1; i <= m; i++) {
            int row = i;
            int col = n;
            if(row * col <= mid) {
                cntK += col;
            } else {
                int low = 1, high = n;
                int j = 0;
                while(low <= high) {
                    int midCol = low + (high-low)/2;
                    if(row * midCol <= mid) {
                        j = midCol;
                        low = midCol+1;
                    } else {
                        high = midCol-1;
                    }
                }

                cntK+= j;
           
            }    
        }

  
        return cntK >= k;
        
    }
    int findKthNumber(int m, int n, int k) {
        
        int low = 1, high = m*n;
        int res = -1;
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(isValid(mid, k, m, n)) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return res;
    }
};