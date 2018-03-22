/* 
 * Problem: 201. Bitwise AND of Numbers Range [medium]
 * Source : https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 * Solver : Baur Krykpayev
 * Date   : 3/22/2018
 */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        int pos = 0;
        
        while(m!=n)
        {
            m >>=1;
            n >>=1;
            pos++;
        }
        
        return n << pos;
    }
};