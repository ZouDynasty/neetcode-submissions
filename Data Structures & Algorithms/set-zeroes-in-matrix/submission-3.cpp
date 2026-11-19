class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        set<int> row_index;
        set<int> col_index;

        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row_index.insert(i);
                    col_index.insert(j);
                }
            }
        }

        for (int col: col_index)
        {
            for (int i = 0; i < rows; i++)
            {
                matrix[i][col] = 0;
            }
        }

        for (int row: row_index)
        {
            for (int i = 0; i < cols; i++)
            {
                matrix[row][i] = 0;
            }
        }
    }
};
