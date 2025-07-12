class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n= nums.size();
        //max_heap

      priority_queue<int> pq(nums.begin(), nums.end());
        k=k-1;
        while(!pq.empty()&& k){
            pq.pop();
            k--;
        }

        return pq.top();
    }
};