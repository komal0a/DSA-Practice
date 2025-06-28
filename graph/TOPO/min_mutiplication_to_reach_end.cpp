class Solution{
public:
    const int mod=100000;
    int minimumMultiplications(vector<int> &arr,int start, int end) {
        vector<int>dist(100000,1e9);
        //pq//
           priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        pq.push({0,start});
        dist[start]=0;

        while(!pq.empty()){
            int steps=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(int i=0; i<arr.size();i++){
                int new_node=( node* arr[i])%mod;
                if(dist[new_node]>steps+1){
                    dist[new_node]=steps+1;
                    pq.push({dist[new_node],new_node});
                }
            }
        }
            return dist[end] == 1e9 ? -1 : dist[end];
    }
};
