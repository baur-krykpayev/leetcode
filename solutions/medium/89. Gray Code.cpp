/* 
 * Problem: 89. Gray Code[medium]
 * Source : https://leetcode.com/problems/gray-code/description/
 * Solver : Baur Krykpayev
 * Date   : 3/12/2018
 */

class Solution {
public:
    vector<int> grayCode(int n) 
    {
        vector<int> ret;
        
        for(int i = 0; i < 1<<n; i++)
        {
            ret.push_back(i^(i>>1));
        }
        
        return ret;
    }
};