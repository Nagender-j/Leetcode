class Item {
    int l;
    int r;
    int wt;
    int idx;
    Item(int l, int r, int wt, int idx) {
        this.l = l;
        this.r = r;
        this.wt =wt;
        this.idx = idx;
    }
    
}

class Result {
    long wt ;
    List<Integer> indices;
    Result(long wt) {
        this.wt = wt;
        indices = new ArrayList<>();
    }

    Result() {
        indices = new ArrayList<>();
        wt = 0;
    }
};

class Solution {
    Result [][] dp;

        Result solve(int i, int k, Item[] a) {
        Result result = new Result();
        if(k  == 0 || i >= a.length) {
            return result;
        }

        if(dp[i][k] != null) {
            return dp[i][k];
        }

        Result notTake = solve(i+1, k, a);
       
       // take
        Result next = solve(getNextPossibleIdx(i, a), k-1, a);
        Result take = new Result(next.wt);
        take.wt += a[i].wt;
        take.indices = new ArrayList<>(next.indices);
        take.indices.add(a[i].idx);

        result = takeMaxOf(notTake, take);

        return dp[i][k] = result;

    }

    Result takeMaxOf(Result a, Result b) {
        Collections.sort(a.indices);
        Collections.sort(b.indices);
        
        if(a.wt > b.wt) return a;
        else if(a.wt < b.wt) return b;
        
        for (int i = 0; i < Math.min(a.indices.size(), b.indices.size()); i++) {
            if (a.indices.get(i) < b.indices.get(i)) return a;
            if (a.indices.get(i) > b.indices.get(i)) return b;
        }

        // All common elements were equal
        return a.indices.size() < b.indices.size() ? a : b;
    }


    private int getNextPossibleIdx(int i, Item[] a)  {
        int low = i+1, high = a.length-1;
        int res = a.length;
        while(low <= high) {
            int mid = low +(high-low)/2;
            if(a[mid].l > a[i].r) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        // cout<<"i : "<<i <<" item : "<<getStr(a[i]) <<" this is : "<< res <<endl;
        return res;
    }
    public int[] maximumWeight(List<List<Integer>> intervals) {
        int n = intervals.size();
        Item[] a = new Item[n];
        for(int i =0 ; i < n; i++) {
            a[i] = new Item(intervals.get(i).get(0), intervals.get(i).get(1), intervals.get(i).get(2), i);
        }
        
        Arrays.sort(a, (p, q) -> {
            if(p.l != q.l) return Integer.compare(p.l, q.l);
            return Integer.compare(p.r, q.r);
        });
        
        int k = 4;
        dp = new Result[n+1][k+1];
       
        Result result = solve(0, 4, a);
        int [] res = new int[result.indices.size()];

        for(int i = 0; i < res.length; i++) {
            res[i] = result.indices.get(i);
        }
        return res;
           
    }
}