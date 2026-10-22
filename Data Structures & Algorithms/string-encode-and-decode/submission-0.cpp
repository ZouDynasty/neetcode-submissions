#include <map>
#include <algorithm>
#include <string>

class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string ans;
        for (int i = 0; i < strs.size(); i++)
        {
            ans = ans + strs[i] + "|";
        }
        return ans;
    }

    vector<string> decode(string s) 
    {
        vector<int> storage;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '|')
            {
                storage.push_back(i);
            }
        }
        int index = 0;
        vector<string> ans;
        for (int i = 0; i < storage.size(); i++)
        {
            ans.push_back(s.substr(index, storage[i] - index));
            index = storage[i] + 1;
        }
        return ans;
    }
};
