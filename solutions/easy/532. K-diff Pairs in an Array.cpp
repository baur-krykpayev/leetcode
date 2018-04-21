/* 
 * Problem: 532. K-diff Pairs in an Array [easy]
 * Source : https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
 * Solver : Baur Krykpayev
 * Date   : 4/21/2018
 */

class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        unordered_map<int,int> map;
        int count = 0;
        for (auto num : nums){map[num]++;}
        
        for (auto it : map)
        {
            if ((k == 0 && it.second > 1) || (k > 0 && map.find(it.first + k) != map.end()))
            {
                count++;
            } 
        }
        
        return count;
    }
};