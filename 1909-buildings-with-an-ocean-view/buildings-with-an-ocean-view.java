class Solution {
    public int[] findBuildings(int[] heights) {
        int n = heights.length;
        int[] mxToRight = new int[n];
        int mx = heights[n-1];
        List<Integer> res = new ArrayList<>();
        res.add(n-1);
        for(int i = n-2; i >= 0; i--) {
            mx = Math.max(heights[i+1], mx);
            if(mx < heights[i]) res.add(i);
        }

        Collections.reverse(res);
        int[] resArr = new int[res.size()];
        for(int i = 0 ; i < res.size(); i++) {
            resArr[i] = res.get(i);
        }


        return resArr;
        
    }
}