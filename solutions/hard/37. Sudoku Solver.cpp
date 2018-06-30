/* 
 * Problem: 37. Sudoku Solver [hard]
 * Source : https://leetcode.com/problems/sudoku-solver/description/
 * Solver : Baur Krykpayev
 * Date   : 06/30/2018
 */
 
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        rows = board.size();
        cols = board[0].size();
        backtrack(board);
    }
    
    
private:
    int rows = 0;
    int cols = 0;
    bool backtrack(vector<vector<char>>& board )
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (board[r][c] == '.')
                {
                    for(int d = 1; d < 10; d++)
                    {
                        char letter = d + '0';
                        if (check(r,c, letter,board))
                        {
                            board[r][c] = letter;
                            if (backtrack(board)){return true;}       
                            board[r][c] = '.';    
                        }
                    }
                    
                    return false;   
                }
            }
        }
        
        return true;
    }
    
    bool check(int r, int c, char target, vector<vector<char>>& board)
    {
        // rows 
        for (int i = 0; i < cols; i++)
        {
            if (board[r][i] == target) {return false;}
        }
        
        // cols 
        for (int i = 0; i < rows; i++)
        {
            if (board[i][c] == target) {return false;}
        }
        
        // 3x3 
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[r - r%3 + i][c - c%3+j] == target) {return false;}
            }          
        }

        return true;
    }
};