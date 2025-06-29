class DisjointSet {
    vector<int> size, parent;
public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionBysize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        } else {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
        int maxrow=0; int maxcol=0;
        for(auto & it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);            
        }

       DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int>mpp;
       for(auto& it:stones){
        int noderow=it[0];
        int nodecol=it[1]+maxrow+1;
        ds.unionBysize(noderow,nodecol);
        mpp[noderow]=1;
        mpp[nodecol]=1;
       }

       int cnt=0;
       for(auto& [node,val]:mpp){
        if(ds.findUpar(node)==node){
            cnt++;
        }
       }
       return n-cnt;
    }
};