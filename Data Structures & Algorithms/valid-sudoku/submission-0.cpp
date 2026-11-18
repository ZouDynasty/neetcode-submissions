class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_map<int, int> row;
            unordered_map<int, int> col;
            for (int j = 0; j < 9; j++)
            {
                if (row.find(board[i][j]) != row.end())
                {
                    return false;
                }
                if (board[i][j] != '.')
                {
                    row[board[i][j]] = 1;
                }
                if (col.find(board[j][i]) != col.end())
                {
                    return false;
                }
                if (board[j][i] != '.')
                {
                    col[board[j][i]] = 1;
                }
            }
        }
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                unordered_map<int, int> square;
                int col = i * 3;
                int row = j * 3;
                for (int k = col; k < col + 3; k++)
                {
                    for(int l = row; l < row + 3; l++)
                    {
                        if (square.find(board[k][l]) != square.end())
                        {
                            return false;
                        }
                        if (board[k][l] != '.')
                        {
                            square[board[k][l]] = 1;
                        }
                    }
                }
            }  
        }
        return true;
        
    }
};