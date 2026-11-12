class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        int sum = 0;
        for (int i = 0; i < 32; i++)
        {
            int bit = (n >> i) & 1;
            sum = sum + bit * pow(2, 31 - i);
        }

        return sum;
    }
};
