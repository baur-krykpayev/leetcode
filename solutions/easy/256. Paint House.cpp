/* 
 * Problem: 256. Paint House [easy]
 * Source : https://leetcode.com/problems/paint-house/description/
 * Solver : Baur Krykpayev
 * Date   : 06/16/2018
 */
 
class Solution {
public:
    int minCost(vector<vector<int>>& costs) 
    {
        int n = costs.size();
        if(!n) {return 0;}
        vector<vector<int>> dp (3, vector<int>(n, INT_MAX));
        dp[0][0] = costs[0][0];
        dp[1][0] = costs[0][1];
        dp[2][0] = costs[0][2];
        
        for (int c = 1; c < costs.size(); c++)
        {
            dp[0][c] = min(dp[1][c-1], dp[2][c-1]) + costs[c][0];
            dp[1][c] = min(dp[0][c-1], dp[2][c-1]) + costs[c][1];
            dp[2][c] = min(dp[0][c-1], dp[1][c-1]) + costs[c][2];
        }
        
        return min(min(dp[0][n-1],dp[1][n-1]), dp[2][n-1]);
    }
};