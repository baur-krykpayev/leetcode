/* 
 * Problem: 531. Lonely Pixel I [medium]
 * Source : https://leetcode.com/problems/lonely-pixel-i/description/
 * Solver : Baur Krykpayev
 * Date   : 5/29/2018
 */

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) 
    {
        int cnt = 0;
        int rows = picture.size();
        int cols = picture[0].size();
        vector<vector<bool>> visited (rows, vector<bool>(cols, false));
        
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
               if (!visited[r][c] && picture[r][c] == 'B')
               {
                   if(traverseRows(r+1, c, visited, picture) 
                      && traverseCols(r, c+1, visited, picture))
                   {
                       cnt++;
                   }
               }
            }
        }
        
        return cnt;
    }
    
private:
    bool traverseRows(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& picture)
    {
        bool lonely = true;
        
        for (int r = row; r < picture.size(); r++)
        {
            visited[r][col] = true;
            if(picture[r][col] == 'B')
            {
                lonely = false;
            }
        }
        
        return lonely;
    }
    
    bool traverseCols(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& picture)
    {
        bool lonely = true;
        
        for (int c = col; c < picture[0].size(); c++)
        {
            visited[row][c] = true;
            if(picture[row][c] == 'B')
            {
                lonely = false;
            }
        }
        
        return lonely;
    }
};