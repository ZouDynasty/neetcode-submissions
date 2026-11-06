class Solution {
public:
    vector<int> countBits(int n) 
    {

        vector<int> result;

        for (int i = 0; i <= n; i++)
        {
            int sum = 0;
            for (int j = 0; j < floor(log2(n)) + 1; j++)
            {
                sum = sum + (i >> j & 1);
            }
            result.push_back(sum);
        }

        return result;
    }
};
