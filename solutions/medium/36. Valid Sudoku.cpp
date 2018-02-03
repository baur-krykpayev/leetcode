/* 
 * Problem: 36. Valid Sudoku[medium]
 * Source : https://leetcode.com/problems/valid-sudoku/description/
 * Solver : Baur Krykpayev
 * Date   : 02/03/2018
 */
 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<int> nums(10, 0);
        
        // rows
        for (int r = 0; r < board.size(); r++)
        {
            clearNums(nums);
            for (int c = 0; c < board[0].size(); c++)
            {
                if (board[r][c] != '.')
                {
                    nums[board[r][c] - '0']++;
                }
            }
            if (!analyzeNums(nums)) {return false;}
        }
        
        // cols
        for (int c = 0; c < board[0].size(); c++)
        {
            clearNums(nums);
            for (int r = 0; r < board[0].size(); r++)
            {
                if (board[r][c] != '.')
                {
                    nums[board[r][c] - '0']++;
                }
            }
            if (!analyzeNums(nums)) {return false;}
        }
        
        // 3x3
        for (int row = 0; row < 9; row = row+3)
        {
            for (int col = 0; col < 9; col = col+3)
            { 
                clearNums(nums);
                for (int r = row; r < row + 3; r++)
                {
                    for (int c = col; c < col + 3; c++)
                    {
                        if (board[r][c] != '.')
                        {
                            nums[board[r][c] - '0']++;
                        }
                    }
                }
                if (!analyzeNums(nums)) {return false;}
            }
        }
        
        return true;
    }
private:
    void clearNums(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
    
    bool analyzeNums(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 1) {return false;}
        }
                
        return true;
    }
};