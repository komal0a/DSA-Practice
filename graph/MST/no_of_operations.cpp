class DisjointSet{
    vector<int>size,parent;
public:
DisjointSet(int n){

    size.resize(n+1,1);
    parent.resize(n+1);
    for(int i=0; i<=n;i++){
        parent[i]=i;
}
    }

    int findUpar(int node){
        if(node==parent[node]){
            return parent[node];
        }
        return parent[node]=findUpar(parent[node]);
    }

    void unionBysize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);

        if(ulp_u==ulp_v)return;

        if(size[ulp_u]<size[ulp_v]){
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=parent[ulp_v];
        }else{
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=parent[ulp_u];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraedges=0;
        for(auto& it: connections){
            int a= it[0];
            int b=it[1];

            if(ds.findUpar(a)==ds.findUpar(b)){
                extraedges++;
            }else{
                ds.unionBysize(a,b);
            }

            }
            int component=0;
            for(int i=0; i<n;i++){
                if(ds.findUpar(i)==i)component++;//different component
        }
        int operations=component-1;
        return (extraedges>=operations)  ? operations:-1;
        }
};