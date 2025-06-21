// Count subsets with sum K
class Solution{
	public:
    int solve(vector<int>& arr, int target,int n,int idx,vector<vector<int>>& dp){
        if(idx == 0) {
        if (target == 0 && arr[0] == 0) return 2; // pick or don't pick the 0
        if (target == 0 || target == arr[0]) return 1;
        return 0;
}

        if(dp[idx][target]!=-1)return dp[idx][target];

        int take=0;
        if(arr[idx<=target]){
            take=arr[idx]+solve(arr,target-arr[idx],n,idx-1,dp);
        }
        int non_take=solve(arr,target,n,idx-1,dp);

        return dp[idx][target]=(take+non_take)%1e9;
    }
	int perfectSum(vector<int>&arr, int K){
        int n= arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));   
        return solve(arr,k,n,n-1,dp);
    }

};

//TABULATION
 vector<vector<int>>dp(n,vector<int>(target+1,0)); 
 
 for(int i=0;i<n;i++){
    dp[i][0]=1;
 }
if (num[0] <= k) {
        dp[0][num[0]] = 1;
    }
   
    for(int i=1; i<n;i++){
        for(int j=1;j<=target;j++){

        }
    }
