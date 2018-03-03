/* 
 * Problem: 79. Word Search[medium]
 * Source : https://leetcode.com/problems/word-search/description/
 * Solver : Baur Krykpayev
 * Date   : 3/2/2018
 */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        vector<vector<bool>> visited (board.size(), vector<bool> (board[0].size(), false));
          
        for (int r = 0; r < board.size(); r++)
        {
            for(int c = 0; c < board[0].size(); c++)
            {
                if (board[r][c] == word[0] && !visited[r][c])
                {
                    visited[r][c] = true;
                    if (helper(0, r, c, visited, board, word)){return true;}
                    visited[r][c] = false;
                }
            }
        }
        
        return false;
    }
    
    bool helper(int pos, int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& board, string word)
    {
        if (pos == word.length()-1) {return true;}
        
        if (c+1 < board[0].size() && word[pos+1] == board[r][c+1] && !visited[r][c+1]) // right
        {
            visited[r][c+1] = true;
            if (helper(pos+1, r, c+1, visited, board, word)) {return true;}
            visited[r][c+1] = false;
        }
       
        if ( 0 <= c-1 && word[pos+1] == board[r][c-1]  && !visited[r][c-1]) // left
        {
            visited[r][c-1] = true;
            if (helper(pos+1, r, c-1, visited, board, word)) {return true;}
            visited[r][c-1] = false;
        }
        
        if (0 <= r-1 && word[pos+1] == board[r-1][c]  && !visited[r-1][c]) // up
        {
            visited[r-1][c] = true;
            if (helper(pos+1, r-1, c, visited, board, word)) {return true;}
            visited[r-1][c] = false;
        }
        
        if (r+1 < board.size() && word[pos+1] == board[r+1][c] && !visited[r+1][c]) // down
        {
            visited[r+1][c] = true;
            if (helper(pos+1, r+1, c, visited, board, word)) {return true;}
            visited[r+1][c] = false;
        }
        
        return false;
    }
};