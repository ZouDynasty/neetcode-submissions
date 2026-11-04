class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<string> q;
        set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);

        bool found = false;
        int words = 1;

        while(q.size() > 0)
        {
            words++;
            int size = q.size();
            bfs_layer(q, visited, wordList, size, found, endWord);
            if (found == true)
            {
                return words;
                break;
            }
        }
        return 0;
    }

    void bfs_layer(queue<string>& q, set<string>& visited, vector<string>& wordList, int& qSize, bool& found, string endWord)
    {
        for (int i = 0; i < qSize; i++)
        {
            string curWord = q.front();
            string reset = curWord;
            q.pop();

            for (int j = 0; j < curWord.size(); j++)
            {
                char oldChar = curWord[j];
                curWord[j] = '*';

                for (int k = 0; k < wordList.size(); k++)
                {
                    string temp = wordList[k];
                    temp[j] = '*';
                    if (curWord == temp)
                    {
                        if (wordList[k] == endWord)
                        {
                            found = true;
                            return;
                        }
                        if (!visited.contains(wordList[k]))
                        {
                            q.push(wordList[k]);
                            visited.insert(wordList[k]);
                        }
                    }
                }
                curWord[j] = oldChar;
            }

        }
    }
};
