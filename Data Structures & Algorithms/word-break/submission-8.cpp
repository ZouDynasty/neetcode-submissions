class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {

        set<string> dict;
        for (int i = 0; i < wordDict.size(); i++)
        {
            dict.insert(wordDict[i]);
        }

        vector<bool> can_start(s.size(), false);
        can_start[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (can_start[j] == true)
                {
                    string sub = s.substr(j, i - j);
                    if (dict.contains(sub))
                    {
                        can_start[i] = true;
                        break;
                    }
                }
            }
        }

        return can_start[s.size()];
    }
};
