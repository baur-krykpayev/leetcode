/* 
 * Problem: 289. Game of Life[medium]
 * Source : https://leetcode.com/problems/game-of-life/description/
 * Solver : Baur Krykpayev
 * Date   : 02/11/2018
 */
 
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        vector<vector<int>> next = board;
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        int nr = r+x;
                        int nc = c+y;
                        if (x == 0 && y == 0){continue;}
                        if (nr>=0 && nc >=0 && nr<rows && nc<cols)
                        {
                            if (board[nr][nc]){neighbors++;}
                        }
                    }
                }
                
                if (board[r][c])
                {
                    if (neighbors == 2 || neighbors == 3) 
                    {
                        next[r][c] = 1;
                    }
                    else
                    {
                        next[r][c] = 0;
                    }
                    
                }
                else
                {
                    if (neighbors == 3) {next[r][c] = 1;}
                }
            }
        }
        
        board = next;
    }
};