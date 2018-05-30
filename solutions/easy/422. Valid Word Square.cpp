/* 
 * Problem: 422. Valid Word Square [easy]
 * Source : https://leetcode.com/problems/valid-word-square/description/
 * Solver : Baur Krykpayev
 * Date   : 5/29/2018
 */

class Solution {
public:
    bool validWordSquare(vector<string>& words) 
    {
        int rows = words.size();
        int cols = 0;
        
        for (string s : words)
        {
            int l = s.length();
            cols = max(cols, l);
        }

        int size = (rows > cols) ? rows : cols;
        vector<vector<char>> matrix(size, vector<char>(size, 'A'));
        
        for (int r = 0; r < rows; r++)
        {
            int temp_cols = words[r].length();
            for (int c = 0; c < temp_cols; c++)
            {
                matrix[r][c] = words[r][c];
            }
        }

        for (int r = 0; r < size; r++)
        {
            for (int c = r; c < size; c++)
            {
                if (matrix[r][c] != matrix[c][r])
                {
                    return false;       
                }
            }
        }
  
        return true;
    }
};