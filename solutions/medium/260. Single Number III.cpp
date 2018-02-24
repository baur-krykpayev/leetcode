/* 
 * Problem: 260. Single Number III[medium]
 * Source : https://leetcode.com/problems/single-number-iii/description/
 * Solver : Baur Krykpayev
 * Date   : 2/24/2018
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int xr = 0;
        for (int num : nums) {xr ^= num;}
        
        int pos = 0;
        while (xr)
        {
            if (xr & 1)
            {
                break;
            }
            xr >>= 1;
            pos++;
        }
        
        vector<int> ret (2, 0);
        for (int num : nums)
        {
            if (num & (1<<pos))
            {
                ret[1] ^= num;
            }
            else
            {
                ret[0] ^= num;
            }
        }
        
        return ret;
    }
};