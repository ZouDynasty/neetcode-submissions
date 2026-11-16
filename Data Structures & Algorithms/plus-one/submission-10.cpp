class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        if (digits.empty())
            return {1};

        if (digits.back() < 9) {
            digits.back() += 1;
            return digits;
        } else {
            digits.pop_back();
            vector<int> result = plusOne(digits);
            result.push_back(0);
            return result;
        }
    }
};