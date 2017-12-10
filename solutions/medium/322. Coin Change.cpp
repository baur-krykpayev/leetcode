/* 
 * Problem: 322. Coin Change[medium]
 * Source : https://leetcode.com/problems/coin-change/description/
 * Solver : Baur Krykpayev
 * Date   : 12/10/2017
 */
 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        for(auto coin : coins)
        {
            if (coin <= amount)
            {
                dp[coin] = 1;    
            }
        }
         
        for (int coin = 1; coin <= amount; coin++)
        {
            for (int k = 0; k < coins.size(); k++)
            {
                if(coins[k] < coin)
                {
                    dp[coin] =  min(dp[coin], dp[coin - coins[k]]+1);
                }
            }
        }
           
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};