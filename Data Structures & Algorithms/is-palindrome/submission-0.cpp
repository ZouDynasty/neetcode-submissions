class Solution {
public:
    bool isPalindrome(string s) 
    {
        string filtered;
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        int len = filtered.length();
        int right_pointer = 0;
        int left_pointer = len - 1;

        for (int i = 0; i < len / 2; i++)
        {
            if (filtered[right_pointer] != filtered[left_pointer])
            {
                return false;
            }
            right_pointer++;
            left_pointer--;
        }
        return true;
    }
};
