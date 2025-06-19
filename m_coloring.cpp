class Solution{
public: 
    bool issafe(unordered_map<int,vector<int>>&mpp,int node,int color,vector<int>&visited){
          for (int adj : mpp[node]) {
            if (visited[adj] == color) return false;
        }
        return true;
    }

    bool solve(unordered_map<int,vector<int>>&mpp,int i,int m,int n,vector<int>&visited){
        if(i==n){
           return true;
        }

        for(int color=0; color<m;color++){
            if(issafe(mpp,i,color,visited)){
                visited[i]=color;
                if(solve(mpp,i+1,m,n,visited))return true;
                visited[i]=-1;
            }
        }
        return false;
    }

    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
    	//your code goes here
    
        vector<int>visited(n,-1);
        unordered_map<int,vector<int>>mpp;
         for (auto& edge : edges) {
            int from = edge[0], to = edge[1];
            mpp[from].push_back(to);
            mpp[to].push_back(from);
        }
        return solve(mpp, 0, m, n, visited);
    }
};