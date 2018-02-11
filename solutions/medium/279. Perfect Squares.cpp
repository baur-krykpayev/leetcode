/* 
 * Problem: 279. Perfect Squares[medium]
 * Source : https://leetcode.com/problems/perfect-squares/description/
 * Solver : Baur Krykpayev
 * Date   : 02/11/2018
 */
 
class Solution {
public:
    int numSquares(int n) 
    {
        int dp[n+1];
        dp[0] = 0;
        vector<int> sq;
        for (int i = 1; i<=n; i++)
        {
            int next_sq = sq.size()+1;
            if(next_sq*next_sq == i)
            {
                dp[i] = 1;
                sq.push_back(i);
            }
            else
            {
                int m = INT_MAX;
                for (int j = 0; j < sq.size(); j++)
                {
                     if (dp[i-sq[j]] < m)
                     {
                         m = dp[i-sq[j]];
                     }
                }
                dp[i] = m+1;
            }
        }
        
        return dp[n];
    }
};