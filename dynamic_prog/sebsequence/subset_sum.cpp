// class Solution{   
// public: 
//     bool isSubsetSum(vector<int>arr, int target){
//         //TABULATION
//         int n= arr.size();
//         vector<vector<bool>>dp(n,vector<bool>(target+1,false));

//            if (arr[0] <= target){
//             dp[0][arr[0]] = true;

//            }

//         for(int i=0; i<n;i++){
//             dp[i][0]=true;
//         }   

//         for(int index=1; index<n;index++){
//             for(int value=1;value<=target;value++){
//                 bool non_take=dp[index-1][value];
//                 bool take=false;
//                 if(arr[index]<=value){
//                     take=dp[index-1][value-arr[index]];
//                 }

//                 dp[index][value]= (take||non_take);
//             }
//         }
//         return dp[n-1][target];
//     }
// };

class Solution{   
public: 
    bool isSubsetSum(vector<int>arr, int target){
        //SPACE OPTIMIAZTION
        int n= arr.size();
        vector<bool>prev(target+1,false);
            
        prev[0]=true;
        if (arr[0] <= target){
            prev[arr[0]] = true;

         }


        for(int index=1; index<n;index++){
            vector<bool>cur(target+1,false);
            cur[0]=true;
            for(int value=1;value<=target;value++){
                bool non_take=prev[value];
                bool take=false;
                if(arr[index]<=value){
                    take=prev[value-arr[index]];
                }

                cur[value]= (take||non_take);
            }
            prev=cur;
        }
        return prev[target];
    }
};
// bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
//     // If the target sum is 0, we have found a subset
//memoIZATION
//     if (target == 0)
//         return true;

//     // If we have reached the first element in 'arr'
//     if (ind == 0)
//         return arr[0] == target;

//     // If the result for this subproblem has already been computed, return it
//     if (dp[ind][target] != -1)
//         return dp[ind][target];

//     // Try not taking the current element into the subset
//     bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

//     // Try taking the current element into the subset if it doesn't exceed the target
//     bool taken = false;
//     if (arr[ind] <= target)
//         taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

//     // Store the result in the dp array to avoid recomputation
//     return dp[ind][target] = notTaken || taken;
// }