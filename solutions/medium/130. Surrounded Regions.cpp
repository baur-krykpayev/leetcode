/* 
 * Problem: 130. Surrounded Regions[medium]
 * Source : https://leetcode.com/problems/surrounded-regions/description/
 * Solver : Baur Krykpayev
 * Date   : 3/18/2018
 */

class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        if (!board.size()) {return;}
        rows = board.size();
        cols = board[0].size();
        
        // corners
        board[0][0] = (board[0][0] == 'O') ? 'A' : board[0][0];
        board[0][cols-1] = (board[0][cols-1] == 'O') ? 'A' : board[0][cols-1];
        board[rows-1][0] = (board[rows-1][0] == 'O') ? 'A' : board[rows-1][0];
        board[rows-1][cols-1] = (board[rows-1][cols-1] == 'O') ? 'A' : board[rows-1][cols-1];
        
        // top and bot
        for (int c = 1; c < cols-1; c++)
        {
            flip(0, c, board);
            flip(rows-1, c, board);
        }
         
        // left and right
        for (int r = 1; r < rows-1; r++)
        {
            flip(r, 0, board);
            flip(r, cols-1, board);
        }
        
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                board[r][c] = (board[r][c] == 'O') ? 'X' : board[r][c];
                board[r][c] = (board[r][c] == 'A') ? 'O' : board[r][c];      
            }
        }
    }

private:
    int rows = 0;
    int cols = 0;
    
    void flip(int i, int j, vector<vector<char>>& board)
    {
        if (board[i][j] == 'O')
        {
            board[i][j] = 'A';
            
            // up, down, left, right
            if (i>0) {flip(i-1, j, board);}
            if (i < rows-1) {flip(i+1, j, board);}              
            if (j > 0) {flip(i, j-1, board);}
            if (j < cols-1) {flip(i, j+1, board);}
        }   
    }
};