/* 
 * Problem: 221. Maximal Square[medium]
 * Source : https://leetcode.com/problems/maximal-square/description/
 * Solver : Baur Krykpayev
 * Date   : 12/12/2017
 */
 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if (!matrix.size()) {return 0;}
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(), 0));
        int area = 0;
        
        for (int row = 0; row < dp.size(); row++)
        {
            for (int col = 0; col < dp[0].size(); col++)
            {
                dp[row][col] = (matrix[row][col] == '1') ? 1 : 0;
                if (dp[row][col]){area=1;}
            }
        }
    
        for (int row = 1; row < dp.size(); row++)
        {
            for (int col = 1; col < dp[0].size(); col++)
            {
                if (dp[row-1][col-1] > 0 && dp[row][col]) 
                {
                    int prev = sqrt(dp[row-1][col-1]);
                    int i = 0;
                    while (++i <= prev)
                    {
                        if(dp[row][col-i] > 0 && dp[row-i][col] > 0)
                        {
                            dp[row][col] = pow(i+1,2);
                            area = (area < dp[row][col]) ? dp[row][col] : area;        
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }    
        }
        
        return area;
    }
};