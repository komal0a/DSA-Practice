//leetcode fibonacci
class Solution {
public:

int solve(int n){
    //space optimization
    if(n==0)return 0;
    int prev2=0;
    int prev=1;
    
    for(int i=2;i<=n;i++){
        int curi=prev+prev2;
        prev2=prev;
        prev=curi;
    }
    
    return prev;
}
int fib(int n) {
    return solve(n);
}
// int solve(int n, vector<int>&dp){
//     if(n<=0)return 0;
//     if(n==1)return 1;
  
//     if(dp[n]!=-1)return dp[n];

//     return dp[n]=solve(n-1,dp)+solve(n-2,dp);
// }
// int fib(int n) {
//     // vector<int>dp(n+1,-1);
//     // return solve(n,dp);
// }


//     class Solution {
    //tabulation
// public:
//     int solve(int n, vector<int>& dp) {
//         if (n == 0) return 0;
//         dp[0] = 0;
//         dp[1] = 1;

//         for (int i = 2; i <= n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }

//         return dp[n];
//     }

//     int fib(int n) {
//         vector<int> dp(n + 1, -1);
//         return solve(n, dp);
//     }
// };

};