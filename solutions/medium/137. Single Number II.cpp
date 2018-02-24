/* 
 * Problem: 137. Single Number II[medium]
 * Source : https://leetcode.com/problems/single-number-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 2/23/2018
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int one = 0;
        int two = 0;
        int mask = 0;
        for (int num : nums)
        {
            two ^= (one & num);
            one ^= num;
            mask = (~one | ~two);
            two &= mask;
            one &= mask;
        }       
        
        return one;
    }
};