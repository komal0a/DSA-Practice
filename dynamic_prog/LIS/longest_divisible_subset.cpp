class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxi = 0;
        int lastind = 0;
        dp[0] = 1;
        hash[0] = 0;
        for (int i = 1; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0 && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastind = i;
            }
        }

        vector<int> temp;
        temp.push_back(arr[lastind]);
        while (hash[lastind] != lastind)
        {
            lastind = hash[lastind];
            temp.push_back(arr[lastind]);
        }

        reverse(temp.begin(), temp.end());

        return temp;
    }
};