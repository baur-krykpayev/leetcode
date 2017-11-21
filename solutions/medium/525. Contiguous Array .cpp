/* 
 * Problem: 525. Contiguous Array [medium]
 * Source : https://leetcode.com/problems/contiguous-array/description/
 * Solver : Baur Krykpayev
 * Date   : 11/19/2017
 */
 
class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map <int, int> hash;
        hash.insert(make_pair(0,-1));

        int retMax = 0;
        int ones = 0;
        int zeroes = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeroes++;
            }
            else
            {
                ones++;
            }

            if(hash.find(zeroes - ones) != hash.end())
            {
                retMax = (retMax > i - hash[zeroes - ones]) ? retMax : i - hash[zeroes - ones];
            }
            else
            {
                hash.insert(make_pair(zeroes-ones, i));
            }
        }

        return retMax;
    }
};