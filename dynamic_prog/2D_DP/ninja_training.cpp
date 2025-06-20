//ninja training

int solve( vector<vector<int>> &points){
    int n= points.size();
    //SPACE OPTIMIZATION
    // Initialize the DP table for the first day (day 0)
    vector<int>prev(4,0);
  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

int maxi=0;
vector<int>cur(4,0);
  for(int day=1;day<points.size();day++){
      for (int last = 0; last < 4; last++) {
            cur[last] = 0;

        for (int task = 0; task < 3; task++) {
          if(task!=last){
               int activity = points[day][task] +prev[task];
          // Update the maximum points for the current day and last activity
          cur[last] = max(cur[last], activity);
          }
      }
      }prev=cur;
  }
  return prev[3];
}
 int ninjaTraining(int n, vector<vector<int>> &points)
{
    return solve(points);    
}
// int solve( vector<vector<int>> &points,vector<vector<int>>& dp){
//     int n= points.size();
//     //TABULATION
//     // Initialize the DP table for the first day (day 0)
//   dp[0][0] = max(points[0][1], points[0][2]);
//   dp[0][1] = max(points[0][0], points[0][2]);
//   dp[0][2] = max(points[0][0], points[0][1]);
//   dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

// int maxi=0;
//   for(int day=1;day<points.size();day++){
//       for (int last = 0; last < 4; last++) {
//             dp[day][last] = 0;

//         for (int task = 0; task < 3; task++) {
//           if(task!=last){
//                int activity = points[day][task] + dp[day - 1][task];
//           // Update the maximum points for the current day and last activity
//           dp[day][last] = max(dp[day][last], activity);
//           }
//       }
//       }
//   }
//   return dp[n-1][3];
// }
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // Write your code here.
//     vector<vector<int>> dp(n, vector<int>(4, -1));
//     return solve(points,dp);    
// }



// int solve(vector<vector<int>> &points,int n, vector<vector<int>>& dp,int last,int day ){
//     //MEMOIZATION
//     if(day==0){
//         int maxi=0;
//         for(int i=0; i<3;i++){
//             if(i!=last){
//                 maxi=max(points[0][i],maxi);
//             }
//         }
//         return dp[day][last]=maxi;
//     }
//     if(dp[day][last]!=-1)return dp[day][last];

//     int maxi=0;
//     for(int i=0;i<3;i++){
//         if(i!=last){
//             int activity=points[day][i]+solve(points,n,dp,i,day-1);
//             maxi=max(maxi,activity);
//         }
//     }
//     return dp[day][last]=maxi;
// }
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // Write your code here.
//     vector<vector<int>> dp(n, vector<int>(4, -1));
//     return solve(points,n,dp,3,n-1);    
// }