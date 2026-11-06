class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int sum = 0;
        for (int i = 0; i < 32; i++)
        {
            sum = sum + (n >> i & 1);
        }

        return sum;
    }
};
