struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
  public:  
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        //your code goes here
           int n = Jobs.size();
        vector<Job> jobList;

        for (int i = 0; i < n; i++) {
            jobList.push_back({Jobs[i][0], Jobs[i][1], Jobs[i][2]});
        }

        sort(jobList.begin(), jobList.end(), comparison);

        int maxDeadline = 0;
        for (auto& job : jobList) {
            maxDeadline = max(maxDeadline, job.dead);
        }

        vector<int> slots(maxDeadline + 1, -1);  // slot[i] = job ID assigned or -1

        int jobCount = 0;
        int maxProfit = 0;

        for (auto& job : jobList) {
            // Try to assign job on latest possible day ≤ deadline
            for (int d = job.dead; d > 0; d--) {
                if (slots[d] == -1) {
                    slots[d] = job.id;
                    jobCount++;
                    maxProfit += job.profit;
                    break;
                }
            }
        }

        return {jobCount, maxProfit};
    } 
};