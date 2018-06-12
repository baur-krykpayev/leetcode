/* 
 * Problem: 421. Maximum XOR of Two Numbers in an Array [medium]
 * Source : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
 * Solver : Baur Krykpayev
 * Date   : 06/11/2018
 */
 
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        int ret = 0;
        int mask = 0;
        
        for(int i = 31; i >= 0; i--)
        {
            mask = mask | (1 << i);
            unordered_set<int> s;
        
            for(int num : nums)
            {
                s.insert(num & mask);
            }
            
            int temp = ret | (1 << i);
            
            for(int pre : s)
            {
                if(s.count(temp ^ pre))
                {
                    ret = temp;
                    break;
                }
            }
        }
        
        return ret;
    }
};