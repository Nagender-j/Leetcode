class Solution {
public:
    vector<int> parent, size, bitwiseAnd;
    void init(int n) {
        parent.assign(n+1, -1);
        bitwiseAnd.assign(n+1, -1);
        for(int i = 0 ;i <n ;i++) {
            parent[i] = i;
        }
        size.assign(n+1, 1);
    }

    int find(int a) {
        if(a == parent[a]) return a;

        return find(parent[a]);
    }

    void Union(int a, int b, int wt) {
        int pa = find(a), pb = find(b);

        if(pa == pb) {
            if(bitwiseAnd[pa] == -1) {
                bitwiseAnd[pa] = wt;
            } else {
                bitwiseAnd[pa] &= wt;
            }

            return;
        }

        if(size[pa] < size[pb]) swap(pa, pb);

        parent[pb] = pa;
        size[pa] += size[pb];

        if(bitwiseAnd[pa] == -1) {
            bitwiseAnd[pa] = wt;
         } else {
            bitwiseAnd[pa] &= wt;
            if(bitwiseAnd[pb] != -1) {
                bitwiseAnd[pa] &= bitwiseAnd[pb];
            }
         }
 
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        init(n);
        
        for(auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            Union(u, v, w);
        }

        vector<int>res;
        for(auto q : query) {
            int s = q[0], t = q[1];
            s = find(s), t = find(t);
            if(s != t) res.push_back(-1);
            else res.push_back(bitwiseAnd[s]);

        }

        return res;
    }
};