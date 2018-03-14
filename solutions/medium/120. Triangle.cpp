/* 
 * Problem: 120. Triangle[medium]
 * Source : https://leetcode.com/problems/triangle/description/
 * Solver : Baur Krykpayev
 * Date   : 3/13/2018
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<int> dp = triangle[triangle.size()-1];
        
        for (int i = triangle.size()-2; i >= 0; i--)
        {
            for (int k = 0; k < triangle[i].size(); k++)
            {
                dp[k] = min(dp[k], dp[k+1]) + triangle[i][k];
            }
        }
        
        return dp[0];
    }
};