/* 
 * Problem: 96. Unique Binary Search Trees[medium]
 * Source : https://leetcode.com/problems/unique-binary-search-trees/description/
 * Solver : Baur Krykpayev
 * Date   : 02/15/2018
 */
 
class Solution {
public:
    int numTrees(int n) 
    {
        int dp[n+1];
        dp[0] = 1; dp[1] = 1;
        
        for (int i = 2; i <= n; i++)
        {
            int catalan = 0;
            for (int j = 0; j < i; j++)
            {
                catalan += dp[j]*dp[i-j-1];
            }
            dp[i] = catalan;
        return dp[n];     
    }
};