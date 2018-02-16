/* 
 * Problem: 646. Maximum Length of Pair Chain[medium]
 * Source : https://leetcode.com/problems/maximum-length-of-pair-chain/description/
 * Solver : Baur Krykpayev
 * Date   : 02/15/2018
 */
 
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        int ret = 1;
        int pos = 0;
        sort(pairs.begin(), pairs.end(), [](auto &left, auto &right) 
            {return left[1] < right[1];});
        
        for (int i = 1; i < pairs.size(); i++)
        {
            if (pairs[pos][1] < pairs[i][0])
            {
                pos = i;
                ret++;
            }
        }
        return ret;
    }
};