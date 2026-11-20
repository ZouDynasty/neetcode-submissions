class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<long long> dp(amount + 1, 0);

        dp[0] = 1;

        for (int j = 0; j < coins.size(); j++)
        {
            for (int i = coins[j]; i < amount + 1; i++)
            {
                if (i - coins[j] < 0)
                {
                    continue;
                }
                if (dp[i] > INT_MAX - dp[i - coins[j]]) 
                { 
                    continue; 
                }
                else
                {
                    dp[i] += dp[i - coins[j]];
                }
            }
        }

        return dp[amount];
    }
};