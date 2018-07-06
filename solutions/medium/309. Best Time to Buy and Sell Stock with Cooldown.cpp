/* 
 * Problem: 309. Best Time to Buy and Sell Stock with Cooldown [medium]
 * Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 * Solver : Baur Krykpayev
 * Date   : 07/06/2018
 */
 
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size(); 
        if (n < 2) {return 0;}
        
        int sell_prev = 0;
        int sell = 0;
        int buy = INT_MIN;
        int buy_prev = 0;
        
        for(int i = 0; i < n; i++)
        {
            buy_prev = buy;
            buy = max(sell_prev - prices[i], buy);
            sell_prev = sell;
            sell = max(buy_prev + prices[i], sell);
        }
        
        return sell;
    }
};