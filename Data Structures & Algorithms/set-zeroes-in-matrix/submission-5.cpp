class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        unordered_map<int, int> row_index;
        unordered_map<int, int> col_index;

        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row_index[i]++;
                    col_index[j]++;
                }
            }
        }

        for (const auto& pair: col_index)
        {
            int col = pair.first;
            for (int i = 0; i < rows; i++)
            {
                matrix[i][col] = 0;
            }
        }

        for (const auto& pair: row_index)
        {
            int row = pair.first;
            for (int i = 0; i < cols; i++)
            {
                matrix[row][i] = 0;
            }
        }
    }
};
