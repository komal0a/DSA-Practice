//subset1 recursion
class Solution {
  public:
    void solve(vector<int>& nums, vector<int>& ans, int n, int i, int sum) {
        if (i == n) {
            ans.push_back(sum);
            return;
        }

        // Include nums[i]
        solve(nums, ans, n, i + 1, sum + nums[i]);

        // Exclude nums[i]
        solve(nums, ans, n, i + 1, sum);
    }

    vector<int> subsetSums(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        solve(nums, ans, n, 0, 0);
        sort(ans.begin(), ans.end());  // optional: if you want the result sorted
        return ans;
    }
};
